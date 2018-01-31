/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:27:18 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/31 12:44:02 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*ft_strfjoin(char *s1, char *s2)
{
	char *new_str;

	new_str = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (new_str);
}

int		ft_can_walk(t_lsl *file)
{
	if (file->root == 1 && (ft_strcmp(file->name, ".") == 0 ||
		ft_strcmp(file->name, "..") == 0))
		return (1);
	if (!file->root && (ft_strcmp(file->name, ".") == 0 ||
		ft_strcmp(file->name, "..") == 0))
		return (0);
	if (file->root == 1)
		return (1);
	if (file->ls->opts.recursive == 1)
		return (1);
	return (0);
}

void	dir_read(t_list *elem)
{
	t_dirent	*dirent;
	t_lsl		new_file;
	t_lsl		*file;

	file = elem->content;
	file->dir = opendir(file->path);
	if (file->type == IDIR && file->dir == NULL)
		file->permission = 0;
	while (file->type == IDIR && file->dir && ft_can_walk(file) &&
		((dirent = readdir(file->dir)) != NULL))
	{
		if (dirent->d_name[0] != '.' || file->ls->opts.all)
		{
			create_file(file->ls, &new_file, 0, ft_strdup(dirent->d_name),
				ft_strfjoin(ft_strjoin(file->path, "/"), dirent->d_name));
			ft_lstadd(&(file->files), ft_lstnew(&new_file, sizeof(t_lsl)));
			/*if (new_file)
				free(new_file);
			new_file = NULL;*/
		}
	}
	file->err = (file->type == IDIR && file->dir == NULL) ? errno : 0;
	if (file->dir)
		closedir(file->dir);
	lssort(file->ls, &(file->files));
}

void	output_dir(t_list *elem)
{
	t_lsl *file;

	file = elem->content;
	if (file->type != IDIR)
		return ;
	// need to write this before anything else can happen
	dir_read(elem);
	/*file->spaces.total = set_total(file->files);
	if (file->ls->opts.longform)
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
		ft_lstdel(&(file->files), &ft_ls_free_file);*/
}
