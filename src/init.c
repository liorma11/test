/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:42:18 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/25 17:43:06 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	create_opts(t_lso *o)
{
	o->recursive = 0;
	o->reverse = 0;
	o->all = 0;
	o->longform = 0;
	o->timemod = 0;
}

void	create_ls(t_ls *ls)
{
	t_lso opts;

	ls->f = NULL;
	ls->d = NULL;
	create_opts(&opts);
	ls->opts = opts;
}
