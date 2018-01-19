/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:09:36 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/19 14:10:19 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int isopt(char c)
{
	return (c == 'R' || c == 'r' || c == 'a' || c == 'l' || c == 't');
}

int parse(t_lso *opts, char opt)
{
	opts->recurse = (opt == 'R') ? 1 : opts->recurse;	
	opts->reverse = (opt == 'r') ? 1 : opts->reverse;	
	opts->all = (opt == 'a') ? 1 : opts->all;
	opts->longform = (opt == 'l') ? 1 : opts->longform;	
	opts->timemod = (opt == 't') ? 1 : opts->timemod;
	return (isopt(opt));
}

t_lso *setopts(void)
{
	t_lso *opts;
	if ((opts = (t_lso *)malloc(sizeof(t_lso))) == NULL)
	{
			ft_puterrv("malloc: failed to allocate ", "lso");
			exit (-1);
	}
	opts->recurse = 0;
	opts->reverse = 0;
	opts->all = 0;
	opts->longform = 0;
	opts->timemod = 0;
	return (opts);
}

// change opts doesnt exist later...
//
t_lso *getopts(int ac, char **av, t_lsi *ls)
{
	t_lso *opts;
	int y;
	int x;

	opts = setopts();
	y = 1;
	while ((y < ac) && av[y][0] == '-' && ft_strcmp(av[y], "-") != 0)
	{
		x = 1;
		if (ft_strcmp(av[y], "--") == 0)
		{
			ls->ai++;
			return (opts);
		}
		while (av[y][x])
		{
			if (!parse(opts, av[y][x]))
				ft_putendl("opt doesnt exits dummy");
			x++;
		}
		y++;
		ls->ai = y;
	}
	return (opts);
}
