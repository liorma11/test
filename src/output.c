/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:52:18 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/30 18:46:09 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	*get_time(t_list *elem)
{
	t_lsl *file;

	file = elem->content;
	/*
	if (file->ls->options.time_last_access)
		return (&file->stat.st_atime);
	else if (file->ls->options.time_creation)
		return (&file->stat.st_ctime);*/
	return (&file->stat.st_mtime);
}

void	pdate(t_list *elem)
{
	char	*str;
	time_t	now;
	t_lsl	*file;

	file = elem->content;
	now = time(0);
	str = ctime(get_time(elem));
	if (*((time_t *)get_time(elem)) > now ||
		(now - MONTH(6)) > *((time_t *)get_time(elem)))
	{
		write(1, ft_strsub(str, 4, 6), 3);
		ft_putstr(" ");
		write(1, ft_strsub(str, 8, 2), 2);
		ft_putstr("  ");
		write(1, ft_strsub(str, 20, 4), 4);
	}
	else
	{
		write(1, ft_strsub(str, 4, 3), 3);
		ft_putchar(' ');
		write(1, ft_strsub(str, 8, 2), 2);
		ft_putchar(' ');
		write(1, ft_strsub(str, 11, 5), 5);
	}
	ft_putstr(" ");
}

void	strsp(char *str, int max_space)
{
	int		spaces;

	spaces = max_space - ft_strlen(str);
	ft_putstr(str);
	while (spaces-- > 0)
		ft_putchar(' ');
	ft_putstr("  ");
}

void	plink(int value, int max_space)
{
	int		spaces;
	int		len;
	char	*str;

	str = ft_itoa(value);
	len = ft_strlen(str);
	if (str)
		free(str);
	spaces = max_space - len;
	while (spaces-- > 0)
		ft_putchar(' ');
	ft_putnbr(value);
	ft_putstr(" ");
}

void	perm_exec(t_lsl *file, int mode_a, int mode_b, char *def)
{
	if (!(file->stat.st_mode & mode_a) && (file->stat.st_mode & mode_b))
		ft_putchar(def[0]);
	else if ((file->stat.st_mode & mode_a) && (file->stat.st_mode & mode_b))
		ft_putchar(def[1]);
	else
		ft_putchar((file->stat.st_mode & mode_a) ? def[2] : def[3]);
}

void	permissions(t_lsl *file)
{
	ft_putstr(file->type == IDIR ? "d" : "");
	ft_putstr(file->type == IFIFO ? "p" : "");
	ft_putstr(file->type == ICHAR ? "c" : "");
	ft_putstr(file->type == IBLOCK ? "b" : "");
	ft_putstr(file->type == IFILE ? "-" : "");
	ft_putstr(file->type == ILINK ? "l" : "");
	ft_putstr(file->type == ISOCK ? "s" : "");
	ft_putchar((file->stat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((file->stat.st_mode & S_IWUSR) ? 'w' : '-');
	perm_exec(file, S_IXUSR, S_ISUID, "Ssx-");
	ft_putchar((file->stat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((file->stat.st_mode & S_IWGRP) ? 'w' : '-');
	perm_exec(file, S_IXGRP, S_ISGID, "Ssx-");
	ft_putchar((file->stat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((file->stat.st_mode & S_IWOTH) ? 'w' : '-');
	perm_exec(file, S_IXOTH, S_ISVTX, "Ttx-");
	ft_putstr("  ");
}

// need to determine spaces during directory read...
void	output_item(t_list *list)
{
	t_lsl *f;

	f = list->content;
	if (!f->exists)
		return (ft_ennoent(f));
	if (!f->ls->opts.longform)
		ft_putendl(f->name);
	else
	{
		//printf("LONGFORM OUTPUT BEGINS:\n\n");
		//permissions !DONE
		permissions(f);
		//number of links !DONE
		plink(f->stat.st_nlink, f->spaces.link);
		//owner
		strsp(f->owner, f->spaces.owner);
		//group
		strsp(f->group, f->spaces.group);
		//size NEED TO HANDLE MIN AND MAJ before.... size.
		//psize(f);
		//time
		pdate(list);
		//name
		ft_putstr(f->name);
		if (f->type == ILINK)
		{
			ft_putstr(" -> ");
			ft_putstr("remember to put the link name dummy");
		}
		ft_putchar('\n');
		//printf("\nEND OF OUTPUT\n");	
	}
}