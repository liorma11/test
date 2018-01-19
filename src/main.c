/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:05:55 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/19 15:00:18 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#define MP 1024

void dw(char *dir, void (*f)(char *))
{
	char name[MP];
	struct dirent *dp;
	DIR *dfd;
	//char *final;

	if ((dfd = opendir(dir)) == NULL)
	{
		ft_puterrv("dw: can't open ", dir);
		return ;
	}
	while ((dp = readdir(dfd)) != NULL)
	{
		if (ft_strcmp(dp->d_name, ".") == 0 || ft_strcmp(dp->d_name, "..") == 0)
			continue ;
		if (ft_strlen(dir) + ft_strlen(dp->d_name) + 2 > sizeof(name))
			ft_puterrv("dw: name is too long for ", dp->d_name);
		else
		{
			sprintf(name, "%s/%s", dir, dp->d_name);
			//final = ft_strjoin(ft_strjoin(dir, "/"), dp->d_name);
			//name = ft_strdup(final);
			(*f)(name);
		}
	}
	closedir(dfd);
}

void ds(char *name)
{
	struct stat buf;

	if (stat(name, &buf) == -1)
	{
		ft_puterrv("ds: can't access ", name);	
		return ;
	}
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		dw(name, ds);
	//ft_putendl("time to dirwalk.");
	printf("%lld %s\n", buf.st_size, name);
}
void runold(int ac, char **av)
{
 	if (ac == 1)
		ds(".");
	else
		while (--ac > 0)
			ds(*++av);
}

// currently malloced: ls, ls->opts /
//
int	main(int ac, char **av)
{
	t_lsi *ls;

	ls = init(ac, av);
	//unit(ls);
	
	return (0);
}
