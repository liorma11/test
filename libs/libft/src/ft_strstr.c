/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:38:35 by bvautour          #+#    #+#             */
/*   Updated: 2017/09/29 11:13:06 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t llen;

	llen = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (*big)
	{
		if (!ft_memcmp(big++, little, llen))
			return ((char *)big - 1);
	}
	return (NULL);
}
