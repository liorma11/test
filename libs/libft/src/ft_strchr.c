/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 21:50:59 by bvautour          #+#    #+#             */
/*   Updated: 2017/10/01 16:40:10 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Strchr:
** locates the first occurrence of c (convert to char) in the
** string pointed to by s. Null terminator considered part of string.
**
** 1. scrape string for a matching character. this will match for '\0' as well.
** 2. return null if the next character is null because it will already exit
**    if it was a match.
** 3. return s casted to char.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s++ == '\0')
			return (NULL);
	}
	return ((char *)s);
}
