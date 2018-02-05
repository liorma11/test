/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:27:18 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/04 23:20:55 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_lstiter_if(t_list *lst, void (*f)(t_list *e), int (*g)(t_list *e))
{
	while (lst)
	{
		if (g(lst))
			f(lst);
		lst = lst->next;
	}
}

int		no_dot_file(t_list *elem)
{
	t_lsl *file;

	file = elem->content;
	if (file->name[0] == '.')
		return (0);
	return (1);
}

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

	// FOUND THE LEAK PROBLEM....
	// I need to malloc in createfile, and free appropriately after... bottom is borked.	
	//printf("read began\n");
	file = elem->content;
	file->dir = opendir(file->path);
	if (file->type == IDIR && file->dir == NULL)
		file->permission = 0;
	while (file->type == IDIR && file->dir && ft_can_walk(file) &&
		((dirent = readdir(file->dir)) != NULL))
	{
		if (dirent->d_name[0] != '.' || file->ls->opts.all)
		{
			create_one(/*file->ls,*/ &new_file, 0, ft_strdup(dirent->d_name),
				ft_strfjoin(ft_strjoin(file->path, "/"), dirent->d_name));
			create_two(&new_file, file->ls);
			ft_lstadd(&(file->files), ft_lstnew(&new_file, sizeof(t_lsl)));
			//if (&new_file)
			//free(&new_file);
			//new_file = 0;
		}
	}
	file->err = (file->type == IDIR && file->dir == NULL) ? errno : 0;
	if (file->dir)
		closedir(file->dir);
	lssort(file->ls, &(file->files));
}

void	pdirname(t_list *elem)
{
	t_lsl	*file;
	file = elem->content;
	// if the number of files is 1 and its not the
	if (!((file->ls->nof == 1 && !file->ls->fp) || (!file->root && !file->ls->opts.recursive) ||(file->ls->opts.all && !file->files && file->permission)))
	{
		if (file->ls->fp)
			ft_putstr("\n");
		ft_putstr(file->path);
		ft_putstr(":\n");
		file->ls->fp = 1;
	}
	if (!file->permission && (file->files ||
		file->ls->opts.recursive || file->root))
		ft_putendl("permission error");//ft_ls_errors_no_permission(file);
	if (file->files && file->ls->opts.longform)
	{
		ft_putstr("total ");
		ft_putnbr(file->spaces.total);
		ft_putstr("\n");
	}
}

void	output_dir(t_list *elem)
{
	t_lsl *file;

	file = elem->content;
	if (file->type != IDIR)
		return ;
	// need to write this before anything else can happen
	dir_read(elem);
	//liststuff(file->files);
	file->spaces.total = set_total(file->files);
	if (file->ls->opts.longform)
		findlargest(file->files);
	pdirname(elem);
	if (!file->ls->opts.all)
		ft_lstiter_if(file->files, &output_item, &no_dot_file);
	else
		ft_lstiter(file->files, &output_item);
	if (file->ls->opts.recursive && !file->ls->opts.all)
		ft_lstiter_if(file->files, &output_dir, &no_dot_file);
	else
		ft_lstiter(file->files, &output_dir);
	// free it boiiii
	if (file->files)
		ft_lstdel(&(file->files), &file_free);
}
