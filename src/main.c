/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:05:55 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/05 14:56:54 by bvautour         ###   ########.fr       */
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
			output_dir(trav);
		else
			output_item(trav);
		trav = trav->next;
	}
	if (list)
		ft_lstdel(&list, &file_free);
}

void	sorting(t_ls ls)
{
	sort_list(&(ls.errors), &ascending_alpha, &get_name);
	lssort(&ls, &ls.dirs);
	lssort(&ls, &ls.items);
}

void	output(t_ls ls)
{
	handle(ls.errors, 0);
	if (ls.items && ls.opts.all)
		findlargest(ls.items);
	handle(ls.items, 0);
	handle(ls.dirs, 1);
}

int		main(int ac, char **av)
{
	t_ls ls;

	create_ls(&ls);
	parse(&ls, ac, av, 0);
	ls.follow = 0;
	sorting(ls);
	output(ls);
	return (0);
}
