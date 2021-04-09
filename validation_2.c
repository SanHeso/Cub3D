/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:40:22 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/09 15:37:39 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	real_screen_size(t_cub *all)
{
	// int		rw;
	// int		rh;

	// mlx_get_screen_size(&rw, &rh);
		all->pars.h = 1080;
		all->pars.w = 1920;
	// if (all->pars.h > rh)
	// if (all->pars.w > rw)
}

void	drctn_plr(t_cub *all, int ch)
{
	if (ch == 'N')
	{
		all->plr.drctn_x = -1;
		all->plr.pln_y = 0.66;
	}
	if (ch == 'S')
	{
		all->plr.drctn_x = 1;
		all->plr.pln_y = -0.66;
	}
	if (ch == 'W')
	{
		all->plr.drctn_y = -1;
		all->plr.pln_x = -0.66;
	}
	if (ch == 'E')
	{
		all->plr.drctn_y = 1;
		all->plr.pln_x = 0.66;
	}
}

