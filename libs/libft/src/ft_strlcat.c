/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:27:45 by bvautour          #+#    #+#             */
/*   Updated: 2017/09/27 21:29:06 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dp;
	const char	*sp;
	size_t		lp;
	size_t		length;

	dp = dst;
	sp = src;
	lp = size;
	while (lp-- != 0 && *dp != '\0')
		dp++;
	length = dp - dst;
	lp = size - length;
	if (lp == 0)
		return (length + ft_strlen(sp));
	while (*sp != '\0')
	{
		if (lp != 1)
		{
			*dp++ = *sp;
			lp--;
		}
		sp++;
	}
	*dp = '\0';
	return (length + (sp - src));
}
