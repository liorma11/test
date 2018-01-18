/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:05:53 by bvautour          #+#    #+#             */
/*   Updated: 2017/10/01 14:34:48 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Memccpy:
** copies bytes from string src to string dst.
** If the character c (as converted to an unsigned char) occurs in the string
** src, the copy stops and a pointer to the byte after the copy of c in
** the string dst is returned.  Otherwise, n bytes are copied, and a NULL
** pointer is returned.
**
** 1. Set up placeholders for dst src and c.
** 2. cast c to unsigned char.
** 3. Declare iterator i for comparison with n to track the copy length.
** 4. copy.
** 5. if the new destination is equal to the c, then return the
**    pointer to the byte after c in dst.
** 6. else, then return NULL.
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char		*cs;
	unsigned char	*cd;
	unsigned char	cc;
	size_t			i;

	i = 0;
	cc = (unsigned char)c;
	cs = src;
	cd = dst;
	while (i < n)
	{
		cd[i] = cs[i];
		if (cd[i] == cc)
			return (&cd[i + 1]);
		i++;
	}
	return (NULL);
}
