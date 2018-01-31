/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:44:59 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/30 19:05:24 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		isopt(char c)
{
	return (c == 'R' || c == 'r' || c == 'a' || c == 'l' || c == 't');
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
	s->owner = 0;
	s->maj = 0;
	s->min = 0;
}

void	set_symlink(t_lsl *f)
{
	f->link = NULL;
	//
}
void	create_file(t_ls *ls, t_lsl *f, char *path)
{
	t_lss spaces;

	space_init(&spaces);
	f->name = path;
	f->path = path;
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
}

void	parse(t_ls *ls, char **av)
{
	t_lsl f;
	
	while (*(++av) && *av[0] == '-')
	{
		opts(&ls->opts, *av);
	}
	if (*av == '\0')
	{
		//printf("searching .\n");
		create_file(ls, &f, ".");
		ft_lstadd(&(ls->dirs), ft_lstnew(&f, sizeof(t_lsl)));
	}
	while (*av)
	{
		//printf("searching for: %s\n", *av);
		create_file(ls, &f, *av++);
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
