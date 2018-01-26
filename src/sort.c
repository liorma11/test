/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:57:17 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/26 14:32:53 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	lslsplit(t_list *src, t_list **head, t_list **back)
{
	t_list *fast;
	t_list *slow;

	if (src == NULL || src->next == NULL)
	{
		*head = src;
		*back = NULL;
	}
	else
	{
		slow = src;
		fast = src->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*head = src;
		*back = slow->next;
		slow->next = NULL;
	}
}

static t_list	*remerge(t_list *a, t_list *b,
	int (*cmp)(void *a_, void *b_), void *(*get_data)(t_list *e))
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (cmp(get_data(a), get_data(b)))
	{
		result = a;
		result->next = remerge(a->next, b, cmp, get_data);
	}
	else
	{
		result = b;
		result->next = remerge(a, b->next, cmp, get_data);
	}
	return (result);
}

void	ft_lstsort(t_list **list,
	int (*cmp)(void *a_, void *b_), void *(*get_data)(t_list *e))
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *list;
	if ((head == NULL) || (head->next == NULL))
		return ;
	lslsplit(head, &a, &b);
	ft_lstsort(&a, cmp, get_data);
	ft_lstsort(&b, cmp, get_data);
	*list = remerge(a, b, cmp, get_data);
}

void	lssort(t_ls *ls, t_list **list)
{
	// remember to un null this...
	ls = NULL;
	ft_lstsort(list, &cmp_asc, &get_name);
	//if (ls->options.is_ordered_by_time)
	//	ft_lstsort(list, &time_asc, &get_elem);
	//if (ls->options.is_reverse)
	//	ft_lstrev(list);
}
