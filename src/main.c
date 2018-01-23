/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:05:55 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/23 11:51:45 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#define MP 1024

// currently malloced: ls, ls->opts /
//
int	main(int ac, char **av)
{
	t_lsi *ls;

	ls = init(ac, av);
	unit(ls);
	
	return (0);
}
