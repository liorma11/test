/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:24:03 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/23 12:15:06 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_file *createf(t_lsi *ls, int dc, char *n, char *p)
{
	t_file *f;
	if ((f = (t_file *)malloc(sizeof(t_file))) == NULL)
	{
		ft_puterrv("malloc: failed to allocate ", "file");
		exit (-1);
		
	}
	f->files = NULL;
	f->ls = ls;
	f->dc = dc;
	f->name = n;
	f->path = p;
	f->exists = (lstat(p, &f->stat) != -1);
	f->type = 0;
	f->type = f->stat.st_mode & S_IFMT;
	// symlink stuff.
	f->owner = (getpwuid(f->stat.st_uid)) ?
		ft_strdup(getpwuid(f->stat.st_uid)->pw_name) :
		ft_itoa(f->stat.st_uid);
	f->group = (getgrgid(f->stat.st_gid)) ?
		ft_strdup(getgrgid(f->stat.st_gid)->gr_name):
		ft_itoa(f->stat.st_gid);
	f->permission = 1;
	f->maj = (f->type == IS_CHAR || f->type == IS_BLOCK) ?
		(int)MAJOR(f->stat.st_rdev) : 0;
	f->min = (f->type == IS_CHAR || f->type == IS_BLOCK) ?
		(int)MINOR(f->stat.st_rdev) : 0;
	return (f);
}

void	freef(t_file **f)
{
	if (*f)
	{
		//clean up this unit testing stuff before ship.
		ft_putendl("file freed");
		printf("free info:\nname: %s, path: %s, exists: %d\n\n", (*f)->name, (*f)->path, (*f)->exists);
		free(*f);
	}
	*f = NULL;
}
void	getf(int ac, char **av, t_lsi *ls)
{
	int i;
	t_file *f;

	i = ls->ai;
	if (ls->nof == 0)
	{
		ls->nof = 1;
		f = createf(ls, 1, ft_strdup("."), ft_strdup("."));
		// add to folders.
		ft_lstadd(&(ls->folders), ft_lstnew(f, sizeof(t_file)));
		// free file malloc.
		freef(&f);
	}
	while (i < ac)
	{
		f = createf(ls, 1, ft_strdup(av[i]), ft_strdup(av[i]));
		if (!f->exists)
			ft_lstadd(&(ls->errors), ft_lstnew(f, sizeof(t_file)));
		else if (f->type == IS_DIR)	
			ft_lstadd(&(ls->folders), ft_lstnew(f, sizeof(t_file)));
		else
			ft_lstadd(&(ls->items), ft_lstnew(f, sizeof(t_file)));
		i++;
		freef(&f);
	}
}

t_lsi	*init(int ac, char **av)
{
	t_lsi *ls;
	if ((ls = (t_lsi *)malloc(sizeof(t_lsi))) == NULL)
	{
			ft_puterrv("malloc: failed to allocate ", "lsi");
			exit (-1);
	}
	ls->ai = 1;
	ls->opts = getopts(ac, av, ls);
	ls->nof = ac - ls->ai;
	getf(ac, av, ls);
	return (ls);	
}
