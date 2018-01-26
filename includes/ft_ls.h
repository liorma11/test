/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:48:33 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/25 20:45:50 by bvautour         ###   ########.fr       */
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
	struct	s_lsl		*n;
	struct	s_lsl		*p;
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
	t_lsl				*f;
	t_lsl				*d;
}						t_ls;

void create_ls(t_ls *ls);
void parse(t_ls *ls, char **av);
void eh_illegal(char opt);
// delet this
void unit(t_ls *ls);
#endif
