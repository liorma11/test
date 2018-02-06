/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:52:18 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/05 16:20:14 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	pdate(t_list *elem)
{
	char	*str;
	time_t	now;
	t_lsl	*file;

	file = elem->content;
	now = time(0);
	str = ctime(get_time(elem));
	if (*((time_t *)get_time(elem)) > now ||
		(now - MONTH(6)) > *((time_t *)get_time(elem)))
	{
		write(1, ft_strsub(str, 4, 6), 3);
		ft_putstr(" ");
		write(1, ft_strsub(str, 8, 2), 2);
		ft_putstr("  ");
		write(1, ft_strsub(str, 20, 4), 4);
	}
	else
	{
		write(1, ft_strsub(str, 4, 3), 3);
		ft_putchar(' ');
		write(1, ft_strsub(str, 8, 2), 2);
		ft_putchar(' ');
		write(1, ft_strsub(str, 11, 5), 5);
	}
	ft_putstr(" ");
}

void	strsp(char *str, int max_space)
{
	int		spaces;

	spaces = max_space - ft_strlen(str);
	ft_putstr(str);
	while (spaces-- > 0)
		ft_putchar(' ');
	ft_putstr("  ");
}

void	pint(int value, int max_space)
{
	int spaces;

	spaces = max_space - ft_numlen(value);
	while (spaces-- > 0)
		ft_putchar(' ');
	ft_putnbr(value);
	ft_putstr(" ");
}

void	psize(t_lsl *file)
{
	int		minor_spaces;
	int		major_spaces;

	minor_spaces = ft_numlen(file->min);
	major_spaces = ft_numlen(file->maj);
	if (file->type == ICHAR || file->type == IBLOCK)
	{
		ft_putchar(' ');
		while ((major_spaces) < file->spaces.maj-- )
			ft_putchar(' ');
		ft_putnbr(file->maj);
		ft_putstr(", ");
		while ((minor_spaces) < file->spaces.min--)
			ft_putchar(' ');
		ft_putnbr(file->min);
		ft_putchar(' ');
	}
	else
	{
		if ((file->spaces.min > 0 || file->spaces.maj > 0))
			pint(file->stat.st_size,
				file->spaces.min + file->spaces.maj + 3);
		else
			pint(file->stat.st_size, file->spaces.size);
	}
}

void	output_item(t_list *list)
{
	t_lsl *f;

	f = list->content;
	if (!f->exists)
		return (ft_ennoent(f));
	f->ls->fp = 1;
	if (!f->ls->opts.longform)
		ft_putendl(f->name);
	else
	{
		permissions(f);
		pint(f->stat.st_nlink, f->spaces.link);
		strsp(f->owner, f->spaces.owner);
		strsp(f->group, f->spaces.group);
		psize(f);
		pdate(list);
		ft_putstr(f->name);
		if (f->type == ILINK)
		{
			ft_putstr(" -> ");
			ft_putstr(f->link);
		}
		ft_putchar('\n');
	}
}
