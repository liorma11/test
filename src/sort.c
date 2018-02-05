/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:57:17 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/05 14:56:26 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		reverse_list(t_list **begin_list)
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	if (begin_list == NULL)
		return ;
	prev = NULL;
	curr = *begin_list;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*begin_list = prev;
}

static void		lslsplit(t_list *src, t_list **head, t_list **back)
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

void			sort_list(t_list **list,
	int (*cmp)(void *a_, void *b_), void *(*get_data)(t_list *e))
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *list;
	if ((head == NULL) || (head->next == NULL))
		return ;
	lslsplit(head, &a, &b);
	sort_list(&a, cmp, get_data);
	sort_list(&b, cmp, get_data);
	*list = remerge(a, b, cmp, get_data);
}

void			lssort(t_ls *ls, t_list **list)
{
	sort_list(list, &ascending_alpha, &get_name);
	if (ls->opts.timemod)
		sort_list(list, &ascending_time, &get_elem);
	if (ls->opts.reverse)
		reverse_list(list);
}
