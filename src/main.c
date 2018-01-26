/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:05:55 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/26 14:34:04 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

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
	unit(&ls);
	return (0);
}
