/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:43:05 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/05 13:54:41 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ascending_alpha(void *a, void *b)
{
	return (ft_strcmp((char *)a, (char *)b) < 0);
}

int		ascending_time(void *a, void *b)
{
	time_t	*time_a;
	time_t	*time_b;
	long	*nano_a;
	long	*nano_b;

	time_a = get_time((t_list *)a);
	time_b = get_time((t_list *)b);
	nano_a = get_time_nano((t_list *)a);
	nano_b = get_time_nano((t_list *)b);
	if (*time_a == *time_b)
		return (*nano_a >= *nano_b);
	else
		return (*time_a > *time_b);
}
