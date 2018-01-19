/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:54:51 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/19 13:57:47 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void testopts(t_lsi *ls)
{
	printf("recurse: %d\nreverse: %d\nall: %d\nlong: %d\ntime: %d\n", ls->opts->recurse,ls->opts->reverse, ls->opts->all, ls->opts->longform, ls->opts->timemod);
}

void unit(t_lsi *ls)
{
	testopts(ls);
}
