/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:56:10 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/05 16:13:55 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>


void	ft_ls_free_file_one(t_lsl *file)
{
	if (!file)
		return ;
	if (file->name)
		free(file->name);
	if (file->path)
		free(file->path);
	if (file->owner)
		free(file->owner);
	if (file->group)
		free(file->group);
	if (file->type == ILINK && file->link)
		free(file->link);
	if (file)
		free(file);
}

void	file_free(void *content, size_t content_size)
{
	t_lsl *file;

	file = content;
	ft_ls_free_file_one(file);
	content_size = 0;
}
