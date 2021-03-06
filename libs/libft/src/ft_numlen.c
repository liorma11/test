/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:13:47 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/30 20:06:43 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(int n)
{
	int		len;
	long	nc;

	len = 0;
	nc = (long)n;
	if (nc <= 0)
	{
		len++;
		nc = -nc;
	}
	while (nc != 0)
	{
		len++;
		nc /= 10;
	}
	return (len);
}
