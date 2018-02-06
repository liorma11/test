/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:57:57 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/05 15:59:13 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

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
