/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:24:14 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/17 18:02:34 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	newcub(t_cub *all)
{
	all->pars.h = 0;
	all->pars.w = 0;
	all->pars.no = 0;
	all->pars.so = 0;
	all->pars.we = 0;
	all->pars.ea = 0;
	all->pars.s = 0;
	all->pars.f[0] = 0, 0, 0;
	all->pars.c[0] = 0, 0, 0;
}

void	flocei(t_cub *all, char *arr, int ch)
{
	char	**tmp;

	i = 0;
	tmp = ft_split(arr, ',');
	while (ch == 'F' && i < 3)
	{
		all->pars.f[i] = (float)ft_atoi(tmp[i]);
		free(tmp[i]);
		i++;
	}
	while (ch == 'C' && i < 3)
	{

		all->pars.c[i] = (float)ft_atoi(tmp[i]);
		free(tmp[i]);
		i++;
	}
}

void	memfree(char ***arr)
{
	int		i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	free((*arr));
}

void	end_of_prog(void)
{
	perror("ERROR! ");
	exit(0);
}

int		mod_atoi(char *str)
{
	int i;
	int u;

	i = 0;
	u = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' \
	|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		end_of_prog();
	while (str[i] >= '0' && str[i] <= '9')
	{
		u = u * 10 + (str[i] - '0');
		i++;
	}
	if (u > 99999)
		return (99999);
	return (u);
}
