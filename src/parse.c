/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:44:59 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/05 16:14:18 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

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
		f->exists = (stat(f->path, &f->stat) != -1);
		if (!f->exists)
			f->exists = (lstat(f->path, &f->stat) != -1);
		else
			f->type = f->stat.st_mode & S_IFMT;
	}
	if (f->type == ILINK)
	{
		f->link = ft_strnew(257);
		readlink(f->path, f->link, 256);
	}
}

void	create_one(t_lsl *f, int root, char *name, char *path)
{
	f->name = name;
	f->path = path;
	f->files = NULL;
	f->root = root;
	f->exists = (lstat(path, &f->stat) != -1);
	f->type = 0;
	f->type = f->stat.st_mode & S_IFMT;
}

void	create_two(t_lsl *f, t_ls *ls)
{
	t_lss spaces;

	space_init(&spaces);
	f->ls = ls;
	set_symlink(f);
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

void	parse(t_ls *ls, int ac, char **av, int i)
{
	t_lsl	f;

	while (*(++av) && *av[0] == '-' && ft_strcmp(*av, "-") != 0 && ++i)
		opts(&ls->opts, *av);
	ls->nof = (ac - i) - 1;
	if (*av == '\0' && ls->nof == 0)
	{
		ls->nof = 1;
		create_one(&f, 1, ft_strdup("."), ft_strdup("."));
		create_two(&f, ls);
		ft_lstadd(&(ls->dirs), ft_lstnew(&f, sizeof(t_lsl)));
	}
	while (*av)
	{
		create_one(&f, 1, ft_strdup(*av), ft_strdup(*av));
		create_two(&f, ls);
		av++;
		if (!f.exists)
			ft_lstadd(&(ls->errors), ft_lstnew(&f, sizeof(t_lsl)));
		else if (f.type == IDIR)
			ft_lstadd(&(ls->dirs), ft_lstnew(&f, sizeof(t_lsl)));
		else
			ft_lstadd(&(ls->items), ft_lstnew(&f, sizeof(t_lsl)));
	}
}
