/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 20:43:26 by bvautour          #+#    #+#             */
/*   Updated: 2017/10/02 21:15:03 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Note to self:
** Make a whitespace detecting function for bonus.
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	char		*str;
	size_t		head;
	size_t		tail;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (!s[i])
		return (ft_strnew(0));
	head = i;
	while (s[i])
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	tail = i + 1;
	str = ft_strnew(tail - head);
	if (str == NULL)
		return (NULL);
	ft_strncpy(str, &s[head], tail - head);
	return (str);
}
