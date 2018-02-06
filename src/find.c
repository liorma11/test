/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:28:07 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/05 16:48:44 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

long long	set_total(t_list *elem)
{
	t_lsl		*file;
	long long	total;

	total = 0;
	while (elem)
	{
		file = elem->content;
		elem = elem->next;
		if (file->name[0] != '.' || file->ls->opts.all)
			total += file->stat.st_blocks;
	}
	return (total);
}

int			file_size(t_list *elem)
{
	t_lsl	*file;
	int		len;

	file = elem->content;
	if (file->type != ICHAR && file->type != IBLOCK)
	{
		len = ft_numlen(file->stat.st_size);
		return (len);
	}
	return (0);
}

int			set_spaces(t_list *list, int (func)(t_list *l))
{
	int		spaces;
	int		largest;
	t_list	*trav;
	t_lsl	*f;

	largest = 0;
	trav = list;
	while (trav)
	{
		f = trav->content;
		if ((f->name[0] != '.' || f->ls->opts.all))
		{
			spaces = func(trav);
			if (spaces > largest)
				largest = spaces;
		}
		trav = trav->next;
	}
	return (largest);
}

void		findlargest(t_list *list)
{
	t_lsl	*f;
	t_list	*trav;

	trav = list;
	while (trav)
	{
		f = trav->content;
		f->spaces.link = set_spaces(list, &link_size);
		f->spaces.owner = set_spaces(list, &owner_size);
		f->spaces.group = set_spaces(list, &group_size);
		f->spaces.maj = set_spaces(list, &maj_size);
		f->spaces.min = set_spaces(list, &min_size);
		f->spaces.size = set_spaces(list, &file_size);
		trav = trav->next;
	}
}
