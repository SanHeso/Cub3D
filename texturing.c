/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:36:56 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/12 18:57:26 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_hit(t_cub *all)
{
	if (all->dda.side == 0)
		all->dda.wall_x = all->plr.pstn_y + all->dda.prp_wll_dst *
		all->dda.r_dr_y;
	else
		all->dda.wall_x = all->plr.pstn_x + all->dda.prp_wll_dst *
		all->dda.r_dr_x;
	all->dda.wall_x -= floor((all->dda.wall_x));
}

void	texture_size(t_cub *all, int width, int height)
{
	all->dda.tex_x = (int)(all->dda.wall_x * (double)width);
	if (all->dda.side == 0 && all->dda.r_dr_x > 0)
		all->dda.tex_x = width - all->dda.tex_x - 1;
	if (all->dda.side == 1 && all->dda.r_dr_y < 0)
		all->dda.tex_x = width - all->dda.tex_x - 1;
	all->dda.step = 1.0 * height / all->dda.line_height;
}

void	texture(t_cub *all)
{
	if (all->dda.side == 1)
	{
		if (all->dda.stp_y > 0)
			texture_size(all, all->ea.t_wdth, all->ea.t_hght);
		if (all->dda.stp_y < 0)
			texture_size(all, all->we.t_wdth, all->we.t_hght);
	}
	else
		if (all->dda.stp_x > 0)
			texture_size(all, all->no.t_wdth, all->no.t_hght);
		if (all->dda.stp_x < 0)
			texture_size(all, all->so.t_wdth, all->so.t_hght);
	all->dda.tex_pstn = (all->dda.draw_start - all->pars.h / 2 +
	all->dda.line_height / 2) *all->dda.step;
}