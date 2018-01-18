/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:40:20 by bvautour          #+#    #+#             */
/*   Updated: 2017/10/01 14:18:56 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Bzero:
** writes n zeroed bytes to the string s.  If n is zero, bzero() does nothing.
**
** 1. set placeholder *ptr for *s
** 2. Decrement n to 0 to determine placement of 0's
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char *ptr;

	ptr = (char *)s;
	while (n-- != 0)
		*ptr++ = 0;
}
