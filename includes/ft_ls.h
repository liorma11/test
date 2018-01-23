/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:48:33 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/22 21:45:46 by bvautour         ###   ########.fr       */
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

# define MONTH(m)	((m) * 30 * 24 * 60 * 60)
# define MAJOR(m)	((__int32_t)(((__uint32_t)(m)) >> 24) & 0xff)
# define MINOR(m)	((__int32_t)((m) & 0xffffff))
typedef struct stat	t_stat;
typedef struct dirent	t_dirent;

enum	e_type
{
	IS_FILE = S_IFREG,
	IS_DIR = S_IFDIR,
	IS_CHAR = S_IFCHR,
	IS_BLOCK = S_IFBLK,
	IS_FIFO = S_IFIFO,
	IS_LINK = S_IFLNK,
	IS_SOCK = S_IFSOCK
};

typedef struct		s_lso
{
	int				recurse;
	int				reverse;
	int				all;
	int				longform;
	int				timemod;
}					t_lso;

typedef struct		s_lsi
{
	int				ai;
	t_lso			*opts;
	int				nof;
	t_list			*items;
	t_list			*folders;
	t_list			*errors;
	int				follow;
}					t_lsi;

typedef struct		s_file
{
	t_list			*files;
	t_lsi			*ls;
	int				dc;
	char			*name;
	char			*path;
	t_stat			stat;
	enum e_type		type;
	int				exists;
	char			*owner;
	char			*group;
	int				permission;
	int				maj;
	int				min;
}					t_file;


typedef struct		s_file_sizes
{
	int				nlink_spaces;
	int				group_spaces;
	int				owner_spaces;
	int				date_spaces;
	int				size_spaces;
	int				major_spaces;
	int				minor_spaces;
	long long		total;
}					t_file_sizes;



t_lsi				*init(int ac, char **av);
t_lso				*getopts(int ac, char **av, t_lsi *ls);
// delet this
void unit(t_lsi *ls);
#endif
