/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 16:22:40 by bvautour          #+#    #+#             */
/*   Updated: 2017/09/29 17:53:01 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	c;
	char	sc;
	size_t	llen;

	if ((c = *little++) != '\0')
	{
		llen = ft_strlen(little);
		while (1)
		{
			while (1)
			{
				if (len-- < 1 || (sc = *big++) == '\0')
					return (NULL);
				if (sc == c)
					break ;
			}
			if (llen > len)
				return (NULL);
			if (ft_strncmp(big, little, llen) == 0)
				break ;
		}
		big--;
	}
	return ((char *)big);
}
