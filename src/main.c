/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:05:55 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/29 15:24:13 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	handle(t_list *list, int is_dir)
{
	t_list *trav;
	trav = list;
	while (trav)
	{
		if (is_dir)
		{
			printf("dirput\n");
			//dirput(trav);
		}
		else
		{
			printf("itemput\n");
			//itemput(trav);
		}
		trav = trav->next;
	}
	if (list)
	{
		printf("list exists time to free with listdel\n");
	}

}

void	*get_name(t_list *elem)
{
	t_lsl *file;

	file = elem->content;
	return (file->name);
}

int		cmp_asc(void *a, void *b)
{
	return (ft_strcmp((char *)a, (char *)b) < 0);
}

int	main(int ac, char **av)
{
	ac = 0;
	t_ls ls;
	create_ls(&ls);
	parse(&ls, av);
	ft_lstsort(&(ls.errors), &cmp_asc, &get_name);
	lssort(&ls, &ls.dirs);
	lssort(&ls, &ls.items);
	handle(ls.errors, 0);
	if (ls.items && ls.opts.all)
		printf("all is called\n");
	handle(ls.items, 0);
	handle(ls.dirs, 1);
	//unit(&ls);
	return (0);
}
