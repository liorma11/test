/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:48:33 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/19 14:35:40 by bvautour         ###   ########.fr       */
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
}					t_lsi;

t_lsi				*init(int ac, char **av);
t_lso				*getopts(int ac, char **av, t_lsi *ls);
// delet this
void unit(t_lsi *ls);
#endif
