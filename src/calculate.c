/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:58:43 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/25 16:30:54 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	step(t_cub *all)
{
	if (all->dda.r_dr_x < 0)
	{
		all->dda.stp_x = -1;
		all->dda.sd_dst_x = (all->plr.pstn_x - all->dda.map_x) *
		all->dda.dlt_dst_x;
	}
	else
	{
		all->dda.stp_x = 1;
		all->dda.sd_dst_x = (all->dda.map_x + 1.0 - all->plr.pstn_x) *
		all->dda.dlt_dst_x;
	}
	if (all->dda.r_dr_y < 0)
	{
		all->dda.stp_y = -1;
		all->dda.sd_dst_y = (all->plr.pstn_y - all->dda.map_y) *
		all->dda.dlt_dst_y;
	}
	else
	{
		all->dda.stp_y = 1;
		all->dda.sd_dst_y = (all->dda.map_y + 1.0 - all->plr.pstn_y) *
		all->dda.dlt_dst_y;
	}
}

void	alg_dda(t_dda *dda, char **map)
{
	while (dda->hit == 0)
	{
		if (dda->sd_dst_x < dda->sd_dst_y)
		{
			dda->sd_dst_x += dda->dlt_dst_x;
			dda->map_x += dda->stp_x;
			dda->side = 0;
		}
		else
		{
			dda->sd_dst_y += dda->dlt_dst_y;
			dda->map_y += dda->stp_y;
			dda->side = 1;
		}
		if (map[dda->map_x][dda->map_y] == '1')
			dda->hit = 1;
	}
}

void	fish_eye(t_dda *dda, t_plr *plr)
{
	if (dda->side == 0)
		dda->prp_wll_dst = (dda->map_x - plr->pstn_x + (1 - dda->stp_x) / 2) /
		dda->r_dr_x;
	else
		dda->prp_wll_dst = (dda->map_y - plr->pstn_y + (1 - dda->stp_y) / 2) /
		dda->r_dr_y;
}

void	height_wall(t_dda *dda, t_pars *pars)
{
	dda->line_height = (int)(pars->h / dda->prp_wll_dst);
	dda->draw_start = -dda->line_height / 2 + pars->h / 2;
	if (dda->draw_start < 0)
		dda->draw_start = 0;
	dda->draw_end = dda->line_height / 2 + pars->h / 2;
	if (dda->draw_end >= pars->h)
		dda->draw_end = pars->h - 1;
}
