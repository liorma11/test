/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:57:17 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/01 17:15:16 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	*get_elem(t_list *elem)
{
	return (elem);
}

int		time_asc(void *a, void *b)
{
	time_t	*time_a;
	time_t	*time_b;
	long	*nano_a;
	long	*nano_b;

	time_a = get_time((t_list *)a);
	time_b = get_time((t_list *)b);
	nano_a = get_time_nano((t_list *)a);
	nano_b = get_time_nano((t_list *)b);
	if (*time_a == *time_b)
		return (*nano_a >= *nano_b);
	else
		return (*time_a > *time_b);
}

void	ft_lstrev(t_list **begin_list)
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
	ft_lstsort(list, &cmp_asc, &get_name);
	if (ls->opts.timemod)
		ft_lstsort(list, &time_asc, &get_elem);
	if (ls->opts.reverse)
		ft_lstrev(list);
}
