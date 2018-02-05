/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:48:33 by bvautour          #+#    #+#             */
/*   Updated: 2018/02/05 00:25:29 by bvautour         ###   ########.fr       */
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
# define MONTH(m)	((m) * 30 * 24 * 60 * 60)
# define MAJ(m)	((__int32_t)(((__uint32_t)(m)) >> 24) & 0xff)
# define MIN(m)	((__int32_t)((m) & 0xffffff))
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



typedef struct			s_lso
{
	int					recursive;
	int					reverse;
	int					all;
	int					longform;
	int					timemod;
	int					last_access;
}						t_lso;

typedef struct			s_ls
{
	t_lso				opts;
	t_list				*errors;
	t_list				*items;
	t_list				*dirs;
	int					follow;
	int					fp;
	int					nof;
}						t_ls;

typedef struct			s_lss
{
	int					link;
	int					group;
	int					owner;
	int					date;
	int					size;
	int					maj;
	int					min;
	long long			total;	
}						t_lss;

typedef struct			s_lsl
{
	int					root;
	char				*name;
	char				*link;
	char				*path;
	int					exists;
	int					err;
	int					type;
	char				*owner;
	char				*group;
	int					permission;
	t_stat				stat;
	t_ls				*ls;
	t_lss				spaces;
	DIR					*dir;
	t_list				*files;
	int					maj;
	int					min;
}						t_lsl;

void					create_ls(t_ls *ls);
void	create_one(/*t_ls *ls,*/ t_lsl *f, int root, char *name, char *path);
void	create_two(t_lsl *f, t_ls *ls);
void	file_free(void *content, size_t content_size);
void	output_dir(t_list *elem);
void					parse(t_ls *ls, int ac, char **av, int i);
void					eh_illegal(char opt);
void	ft_ennoent(t_lsl *f);
void	ft_lstsort(t_list **list,
	int (*cmp)(void *a_, void *b_), void *(*get_data)(t_list *e));
void	*get_time_nano(t_list *elem);
void	*get_time(t_list *elem);
void	lssort(t_ls *ls, t_list **list);
void	*get_name(t_list *elem);
int		cmp_asc(void *a, void *b);
void	output_item(t_list *list);
void	findlargest(t_list *list);
long long	set_total(t_list *elem);

/* OPTIONS */
int		isopt(char c);
void	opts(t_lso *opts, char *av);

// delet this
void unit(t_ls *ls);
void liststuff(t_list *list);

#endif
