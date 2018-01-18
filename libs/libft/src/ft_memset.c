/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 18:11:25 by bvautour          #+#    #+#             */
/*   Updated: 2017/10/01 14:09:25 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Memset:
** writes len bytes of value c (converted to an unsigned char) to the string b.
**
** 1. Define placeholder *s to manipulate string *b.
** 2. Decrement length to determine how long to copy c to b.
** 3. Copy c to b through placeholder s.
** 4. return b.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *s;

	s = b;
	while (len-- != 0)
		*s++ = (unsigned char)c;
	return (b);
}
