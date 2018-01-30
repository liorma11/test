/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:53:59 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/29 19:15:38 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_ennoent(t_lsl *f)
{
	ft_putstr_fd("ls: ", 2);
	if (f->name == '\0')
		ft_putstr_fd("fts_open", 2);
	else
		ft_putstr_fd(f->name, 2);
	ft_puterr(": No such file or directory");
	if (f->name[0] == '\0')
		exit(1);
}

void	eh_illegal(char opt)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(opt, 2);
	ft_putchar_fd('\n', 2);
	ft_puterr("usage: ls [-Rralt] [file ...]");
	exit(1);
}
