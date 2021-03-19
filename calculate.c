/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:58:43 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/19 16:16:18 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		step(t_cub *all)
{
	if (all->dda.r_dr_x < 0)
	{
		all->dda.stp_x = -1;
		all->dda.sd_dst_x = (all->plr.pstn_x - all->dda.map_x) *
		all->dda.dlt_dst_x
	}
	else
	{
		all->dda.stp_x = 1;
		all->dda.sd_dst_x = (all->plr.pstn_x + 1.0 - all->plr.pstn_x *
		all->dda.dlt_dst_x
	}
	if (all->dda.r_dr_y < 0)
	{
		all->dda.stp_y = -1;
		all->dda.sd_dst_y = (all->plr.pstn_y - all->dda.map_y) *
		all->dda.dlt_dst_y
	}
	else
	{
		all->dda.stp_y = 1;
		all->dda.sd_dst_y = (all->plr.pstn_y + 1.0 - all->plr.pstn_y *
		all->dda.dlt_dst_y
	}
}

