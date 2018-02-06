/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:36:23 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/05 16:37:35 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_lstiterc(t_list *lst, void (*f)(t_list *e), int (*g)(t_list *e))
{
	while (lst)
	{
		if (g(lst))
			f(lst);
		lst = lst->next;
	}
}

int		no_dot_file(t_list *elem)
{
	t_lsl *file;

	file = elem->content;
	if (file->name[0] == '.')
		return (0);
	return (1);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char *new_str;

	new_str = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (new_str);
}
