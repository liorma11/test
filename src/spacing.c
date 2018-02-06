/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:06:44 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/05 16:08:12 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		link_size(t_list *l)
{
	int		len;
	t_lsl	*f;

	f = l->content;
	len = ft_numlen(f->stat.st_nlink);
	return (len);
}

int	owner_size(t_list *elem)
{
	t_lsl *file;

	file = elem->content;
	return (ft_strlen(file->owner));
}

int	group_size(t_list *elem)
{
	t_lsl *file;

	file = elem->content;
	return (ft_strlen(file->group));
}

int	min_size(t_list *elem)
{
	int		len;
	t_lsl	*file;

	file = elem->content;
	if (file->type == ICHAR || file->type == IBLOCK)
	{
		len = ft_numlen(file->min);
		return (len);
	}
	return (0);
}

int	maj_size(t_list *elem)
{
	int		len;
	t_lsl	*file;

	file = elem->content;
	if (file->type == ICHAR || file->type == IBLOCK)
	{
		len = ft_numlen(file->maj);
		return (len);
	}
	return (0);
}
