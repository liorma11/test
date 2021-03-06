/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:43:05 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/05 15:54:59 by bvautour         ###   ########.fr       */
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
	long	*mica;
	long	*micb;

	time_a = get_time((t_list *)a);
	time_b = get_time((t_list *)b);
	mica = get_time_micro((t_list *)a);
	micb = get_time_micro((t_list *)b);
	if (*time_a == *time_b)
		return (*mica >= *micb);
	else
		return (*time_a > *time_b);
}
