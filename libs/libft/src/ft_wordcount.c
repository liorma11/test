/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 21:37:50 by bvautour          #+#    #+#             */
/*   Updated: 2017/10/04 11:34:22 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Wordcount:
**	Counts the words in string s, delimited by char c.
**	Returns the count of words in the string.
**
**	1. Skip over any delimiters at the beginning of the string.
**	2. skip over a word when one is found.
**	3. check to see if the previous character wasn't the delimiter.
**		if it was, start the outer loop again, if it wasn't increment the count
*/
#include "libft.h"

int		ft_wordcount(char const *s, char c)
{
	int		cnt;

	cnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s && *s != c)
			s++;
		if (*(s - 1) != c)
			cnt++;
	}
	return (cnt);
}
