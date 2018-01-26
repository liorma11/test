/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:54:51 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/25 17:52:31 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void unit(t_ls *ls)
{
	printf("\nUNIT TEST\n");
	printf("options selected:\nR: %d\nr: %d\na: %d\nl: %d\nt: %d\n", ls->opts.recursive, ls->opts.reverse, ls->opts.all, ls->opts.longform, ls->opts.timemod);	
}
