/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:05:55 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/18 11:28:01 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void ds(char *name)
{
	struct stat buf;

	if (stat(name, &buf) == -1)
	{
		ft_puterrv("ds: can't access ", name);	
		return ;
	}
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		ft_putendl("time to dirwalk.");
}

int	main(int ac, char **av)
{
	if (ac == 1)
		ds(".");
	else
		while (--ac > 0)
			ds(*++av);
	return (0);
}
