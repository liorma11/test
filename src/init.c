/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:24:03 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/19 14:36:37 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_lsi *init(int ac, char **av)
{
	t_lsi *ls;
	if ((ls = (t_lsi *)malloc(sizeof(t_lsi))) == NULL)
	{
			ft_puterrv("malloc: failed to allocate ", "lsi");
			exit (-1);
	}
	ls->ai = 1;
	ls->opts = getopts(ac, av, ls);
	ls->nof = ac - ls->ai;
	return (ls);	
}
