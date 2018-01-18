/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:08:57 by bvautour          #+#    #+#             */
/*   Updated: 2017/10/01 16:05:55 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Memchr
** locates the first occurrence of c (converted to an uns char) in string s.
**
** 1. declare placeholder for s.
** 2. decrement n to determine length to search over.
** 3. if the pointer matches casted c, return the pointer.
** 4. else return null.
*/
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *sp;

	sp = (unsigned char *)s;
	while (n-- != 0)
	{
		if (*sp == (unsigned char)c)
			return (sp);
		sp++;
	}
	return (NULL);
}
