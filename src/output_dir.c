/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:27:18 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/31 11:28:38 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_ls_show_dir(t_list *elem)
{
	t_lsl *file;

	file = elem->content;
	if (file->type != IS_DIR)
		return ;
	ft_ls_read_dir(elem);
	file->sizes.total = get_total(file->files);
	if (file->ls->options.is_full_show)
		get_max_values(file->files);
	ft_ls_show_dir_name(elem);
	if (!file->ls->options.is_all_files)
		ft_lstiter_if(file->files, &ft_ls_show_file, &no_dot_file);
	else
		ft_lstiter(file->files, &ft_ls_show_file);
	if (file->ls->options.is_recursive && !file->ls->options.is_all_files)
		ft_lstiter_if(file->files, &ft_ls_show_dir, &no_dot_file);
	else
		ft_lstiter(file->files, &ft_ls_show_dir);
	if (file->files)
		ft_lstdel(&(file->files), &ft_ls_free_file);
}
