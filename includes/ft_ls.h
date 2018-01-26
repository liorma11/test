/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:48:33 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/26 14:18:17 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <libft.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# define NLIMIT 1024
typedef struct stat	t_stat;
typedef struct dirent	t_dirent;

enum	e_ftype
{
	IFILE = S_IFREG,
	IDIR = S_IFDIR,
	ICHAR = S_IFCHR,
	IBLOCK = S_IFBLK,
	IFIFO = S_IFIFO,
	ILINK = S_IFLNK,
	ISOCK = S_IFSOCK
};

typedef struct			s_lsl
{
	char				*name;
	char				*path;
	int					exists;
	int					type;
	char				*owner;
	char				*group;
	int					permission;
	t_stat				stat;
}						t_lsl;

typedef struct			s_lso
{
	int					recursive;
	int					reverse;
	int					all;
	int					longform;
	int					timemod;
}						t_lso;

typedef struct			s_ls
{
	t_lso				opts;
	t_list				*errors;
	t_list				*items;
	t_list				*dirs;
}						t_ls;

void create_ls(t_ls *ls);
void parse(t_ls *ls, char **av);
void eh_illegal(char opt);
void	ft_lstsort(t_list **list,
	int (*cmp)(void *a_, void *b_), void *(*get_data)(t_list *e));
void	lssort(t_ls *ls, t_list **list);
void	*get_name(t_list *elem);
int		cmp_asc(void *a, void *b);
// delet this
void unit(t_ls *ls);
void liststuff(t_list *list);

#endif
