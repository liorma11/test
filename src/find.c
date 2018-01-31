/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:28:07 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/30 19:03:52 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		link_size(t_list *l)
{
	char	*str;
	int		len;
	t_lsl	*f;

	f = l->content;
	str = ft_itoa(f->stat.st_nlink);
	len = ft_strlen(str);
	if (str)
		free(str);
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

int		set_spaces(t_list *list, int (func)(t_list *l))
{
	int spaces;
	int largest;
	t_list *trav;
	t_lsl *f;

	largest = 0;
	trav = list;
	while(trav)
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

void	findlargest(t_list *list)
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
		trav = trav->next;
	}		
}
