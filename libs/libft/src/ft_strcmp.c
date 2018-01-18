/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:28:24 by bvautour          #+#    #+#             */
/*   Updated: 2017/10/01 20:28:36 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	char	cmp1;
	char	cmp2;
	int		i;

	i = 0;
	while (*(s1 + i) != 0 && *(s1 + i) == *(s2 + i))
		i++;
	cmp1 = s1[i];
	cmp2 = s2[i];
	return ((unsigned char)cmp1 - (unsigned char)cmp2);
}
