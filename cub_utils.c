/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:24:14 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/10 19:50:17 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	newcub(t_cub *all)
{
	all->pars.heightr = 0;
	all->pars.widthr = 0;
	all->pars.NO = 0;
	all->pars.SO = 0;
	all->pars.WE = 0;
	all->pars.EA = 0;
	all->pars.S = 0;
	all->pars.F[0] = 0, 0, 0;
	all->pars.C[0] = 0, 0, 0;
}

void	flocei(t_cub *all, char *arr, int ch)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(arr, ',');
	while (ch == 'F' && i < 3)
	{
		all->pars.F[i] = (float)ft_atoi(tmp[i]);
		i++;
	}
	while (ch == 'C' && i < 3)
	{
		all->pars.C[i] = (float)ft_atoi(tmp[i]);
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
