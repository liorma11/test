/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterrv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:22:25 by bvautour          #+#    #+#             */
/*   Updated: 2018/01/18 11:35:08 by bvautour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puterrv(char *str, char *var)
{
	char *err;
	char *ferrno;

	err = ft_strjoin(str, var);
	ferrno = ft_strjoin(": ", strerror(errno));
	ft_puterr(ft_strjoin(err, ferrno));
}
