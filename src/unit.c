/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:54:51 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/31 13:27:48 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void liststuff(t_list *list)
{
	t_lsl *item;
	if (!list)
		printf("no items calculated\n");
	while (list)
	{
		item = list->content;
		printf("item name: %s\n", item->name);
		printf("maj %d, min %d\n", item->spaces.maj, item->spaces.min);
		if (list->next == NULL)
			break ;
		list = list->next;
	}
}

void unit(t_ls *ls)
{
	printf("\nUNIT TEST BEGINS\n");
	printf("options selected:\nR: %d\nr: %d\na: %d\nl: %d\nt: %d\n", ls->opts.recursive, ls->opts.reverse, ls->opts.all, ls->opts.longform, ls->opts.timemod);
	printf("\nLIST CHECK\n----------\nErrors:\n");
	liststuff(ls->errors);
	printf("\nDirectory:\n");
	liststuff(ls->dirs);
	printf("\nItems:\n");
	liststuff(ls->items);
}
