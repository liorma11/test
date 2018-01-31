/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 13:35:40 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/30 20:06:30 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		numlen;
	long	nc;
	char	*str;

	numlen = ft_numlen(n);
	nc = (long)n;
	str = ft_strnew(numlen);
	if (str == NULL)
		return (NULL);
	str[numlen--] = '\0';
	if (nc < 0)
	{
		str[0] = '-';
		nc = -nc;
	}
	str[numlen--] = (nc % 10) + '0';
	while (nc >= 10)
	{
		nc /= 10;
		str[numlen--] = (nc % 10) + '0';
	}
	return (str);
}
