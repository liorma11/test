/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:54:51 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/22 21:46:00 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void testopts(t_lsi *ls)
{
	printf("FLAGS: \nrecurse: %d\nreverse: %d\nall: %d\nlong: %d\ntime: %d\n\n", ls->opts->recurse,ls->opts->reverse, ls->opts->all, ls->opts->longform, ls->opts->timemod);
}

void testfile(t_lsi *ls)
{
	t_list *t;
	t_file *f;

	t = ls->folders;
	//while (t->next)
	//{
		f = t->content;
		printf("FILE CONTENT:\nname: %s, path: %s, exists: %d\n", f->name, f->path, f->exists);
		printf("depth count: %d, owner: %s, group: %s\n", f->dc, f->owner, f->group);
		printf("perm: %d, maj: %d, min: %d\n\n", f->permission, f->maj, f->min);
	//	t = t->next;
	//}
}

void unit(t_lsi *ls)
{
	testopts(ls);
	testfile(ls);
}
