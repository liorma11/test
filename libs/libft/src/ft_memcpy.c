/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:10:53 by bvautour          #+#    #+#             */
/*   Updated: 2017/10/01 14:25:20 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Memcpy:
** Copies n bytes from memory area src to memory area dst.
** If dst and src overlap, behavior is undefined.
**
** 1. setup placeholders *s and *d to manipulate src and dst.
** 2. decrement n to 0 to get copy length.
** 3. copy.
** 4. return the original value of destination.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = (const char *)src;
	d = (char *)dst;
	while (n-- != 0)
		*d++ = *s++;
	return (dst);
}
