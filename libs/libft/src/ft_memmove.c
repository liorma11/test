/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:22:48 by bvautour          #+#    #+#             */
/*   Updated: 2017/10/01 15:49:08 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Memmove:
** function copies len bytes from string src to string dst.
** The two strings may overlap; the copy is always done in a non-destructive
** manner.
**
** 1. Declare placeholders for dest and src and an iterator
** 2. check to see if dst or src is bigger.
** 3. if src is bigger copy forwards
** 4. if dest is bigger copy backwards.
** 5. return dst.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*cd;
	const unsigned char	*cs;
	size_t				i;

	cd = dst;
	cs = src;
	if (dst < src)
	{
		i = 0;
		while (i < n)
		{
			cd[i] = cs[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (n--)
			cd[n] = cs[n];
	}
	return (dst);
}
