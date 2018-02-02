/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:44:59 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/01 17:52:23 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		isopt(char c)
{
	return (c == 'R' || c == 'r' || c == 'a' || c == 'l' || c == 't' || c == 'u');
}

void	opts(t_lso *opts, char *av)
{
	while(*(++av))
	{
		if (isopt(*av))
		{
			opts->recursive = (*av == 'R') ? 1 : opts->recursive;	
			opts->reverse = (*av == 'r') ? 1 : opts->reverse;	
			opts->all = (*av == 'a') ? 1 : opts->all;
			opts->longform = (*av == 'l') ? 1 : opts->longform;	
			opts->timemod = (*av == 't') ? 1 : opts->timemod;
			if (*av == 'u')
				opts->last_access = 1;
		}
		else
			eh_illegal(*av);
	}
}

void	space_init(t_lss *s)
{
	s->link = 0;
	s->group = 0;
	s->date = 0;
	s->size = 0;
	s->owner = 0;
	s->maj = 0;
	s->min = 0;
	s->total = 0;
}

void	set_symlink(t_lsl *f)
{
	f->link = NULL;
	if (f->ls->follow && f->type == ILINK
			&& !f->ls->opts.longform
			&& !f->ls->opts.timemod)
	{
		// still need to handle this condition....
		printf("follow is true, type is link, and optinos long and time are not on\n");
	}
	if (f->type == ILINK)
	{
		f->link = ft_strnew(257);
		readlink(f->path, f->link, 256);	
	}
}
void	create_file(t_ls *ls, t_lsl *f, int root, char *name, char *path)
{
	t_lss spaces;

	space_init(&spaces);
	f->name = name;
	f->path = path;
	f->files = NULL;
	f->root = root;
	f->exists =	(lstat(path, &f->stat) != -1);
	f->type = 0;
	f->ls = ls;
	f->type = f->stat.st_mode & S_IFMT;
	set_symlink(f);
	// maybe delete this sizing init later
	f->spaces = spaces; 
	f->owner = (getpwuid(f->stat.st_uid)) ?
		ft_strdup(getpwuid(f->stat.st_uid)->pw_name) :
		ft_itoa(f->stat.st_uid);
	f->group = (getgrgid(f->stat.st_gid)) ?
		ft_strdup(getgrgid(f->stat.st_gid)->gr_name) :
		ft_itoa(f->stat.st_gid);
	f->permission = 1;
	f->maj = (f->type == ICHAR || f->type == IBLOCK) ?
		(int)MAJ(f->stat.st_rdev) : 0;
	f->min = (f->type == ICHAR || f->type == IBLOCK) ?
		(int)MIN(f->stat.st_rdev) : 0;
}

void	parse(t_ls *ls, int ac,  char **av)
{
	t_lsl f;
	int i;

	i = 0;
	while (*(++av) && *av[0] == '-')
	{
		 opts(&ls->opts, *av);
		 i++;
	}
	//printf("preassign ac: %d, i: %d, nof: %d\n", ac, i, ls->nof);
	ls->nof = (ac - i) - 1;
	//printf("post nof %d\n", ls->nof);
	if (*av == '\0' && ls->nof == 0)
	{
		//printf("searching .\n");
		ls->nof = 1;
		// ADDED STRDUPS DONT FORGET TO REMOVE IF IT DOESNT FIX THE LEAKs;
		create_file(ls, &f, 1, ft_strdup("."), ft_strdup("."));
		ft_lstadd(&(ls->dirs), ft_lstnew(&f, sizeof(t_lsl)));
	}
	while (*av)
	{
		//printf("searching for: %s\n", *av);
		// ADDDED STRDUPS HERE DONT FORGET TO REMOVE IF IT DOENST FIX
		create_file(ls, &f, 1, ft_strdup(*av), ft_strdup(*av));
		av++;
		if (!f.exists)
		{
			//printf("file %s does not exist with a value of %d add to errors list\n", f.name, f.exists);
			ft_lstadd(&(ls->errors), ft_lstnew(&f, sizeof(t_lsl)));
		}
		else if (f.type == IDIR)
		{
			//printf("file %s is a directory... add it to the directory list\n", f.name);
			ft_lstadd(&(ls->dirs), ft_lstnew(&f, sizeof(t_lsl)));
		}
		else
		{
			//printf("file %s is any other type of file... add it to the items list\n", f.name);
			ft_lstadd(&(ls->items), ft_lstnew(&f, sizeof(t_lsl)));
		}
	}
}
