/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:42:03 by bvautour          #+#    #+#             */
/*   Updated: 2017/09/26 16:35:15 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int duration;
	int i;

	i = 0;
	duration = ft_strlen(src) + 1;
	while (i < duration)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
