/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:49:56 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/05 15:53:36 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	*get_time(t_list *elem)
{
	t_lsl *file;

	file = elem->content;
	if (file->ls->opts.last_access)
		return (&file->stat.st_atime);
	return (&file->stat.st_mtime);
}

void	*get_time_micro(t_list *elem)
{
	t_lsl *file;

	file = elem->content;
	if (file->ls->opts.last_access)
		return (&file->stat.st_atimespec.tv_nsec);
	return (&file->stat.st_mtimespec.tv_nsec);
}
