/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:47:21 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/05 13:48:14 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	*get_elem(t_list *elem)
{
	return (elem);
}

void	*get_name(t_list *elem)
{
	t_lsl *file;

	file = elem->content;
	return (file->name);
}
