/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 20:43:24 by bvautour          #+#    #+#             */
/*   Updated: 2017/10/05 15:50:55 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Strsplit:
**	Split string s based on c delimiter. if allocation fails... return null.
**
**	1. guard against null string.
**	2. count the words in the string with wordcount, this will be array length.
**	3. declare the array with malloc using the length of the array casting to
**	   char**. if the allocation fails return null.
**	4. send to the first sub func:
**
**	Ssparsetoarr:
**	The middle-man function. Handles the array of strings returned by
**	strpartition. Returns the array to strsplit
**
**	5. while the index of the array is less than the length of the array,
**	   skip whitespace, then when you reach a word count its length.
**	6. if the string has ended or if it matches a white space again,
**	   pop the string created by strpartition into the array.
**	7. Close the array. Then return it to strsplit.
**
**	Strpartition
**
**	1. Create a new string, and populate it backwards.
**	2. Return to the string to the parser.
*/

#include "libft.h"

static char		*ft_strpartition(char const *s, int slen, long index)
{
	char	*str;

	str = ft_strnew(slen);
	if (str == NULL)
		return (NULL);
	str[slen--] = '\0';
	while (slen >= 0)
		str[slen--] = s[index--];
	return (str);
}

static char		**ft_ssparsetoarr(char const *s, char **a, int alen, char c)
{
	int		ai;
	int		slen;
	long	i;

	i = 0;
	ai = 0;
	while (ai < alen)
	{
		slen = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			slen++;
		}
		if (s[i] == '\0' || s[i] == c)
			a[ai++] = ft_strpartition(s, slen, i - 1);
	}
	a[ai] = NULL;
	return (a);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**a;
	int		alen;

	if (s == NULL)
		return (NULL);
	alen = ft_wordcount(s, c);
	if (!(a = (char **)malloc(sizeof(char *) * alen + 1)))
		return (NULL);
	return (ft_ssparsetoarr(s, a, alen, c));
}
