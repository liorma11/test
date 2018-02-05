/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 00:23:41 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/05 00:45:46 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		isopt(char c)
{
	return (c == 'R' || c == 'r' || c == 'a' ||
			c == 'l' || c == 't' || c == 'u');
}

void	opts(t_lso *opts, char *av)
{
	if (ft_strcmp(av, "--") == 0)
		return ;
	while (*(++av))
	{
		if (isopt(*av))
		{
			opts->recursive = (*av == 'R') ? 1 : opts->recursive;
			opts->reverse = (*av == 'r') ? 1 : opts->reverse;
			opts->all = (*av == 'a') ? 1 : opts->all;
			opts->longform = (*av == 'l') ? 1 : opts->longform;
			opts->timemod = (*av == 't') ? 1 : opts->timemod;
			if (*av == 'u')
				opts->last_access = 1;
		}
		else
			eh_illegal(*av);
	}
}
