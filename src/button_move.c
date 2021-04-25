/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:58:06 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/25 16:50:47 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		key_press(int keycode, t_cub *all)
{
	if (keycode == 13)
		all->plr.bttn_w = 1;
	else if (keycode == 0)
		all->plr.bttn_a = 1;
	else if (keycode == 1)
		all->plr.bttn_s = 1;
	else if (keycode == 2)
		all->plr.bttn_d = 1;
	else if (keycode == 53)
		exit(0);
	if (keycode == 124)
		all->plr.rttn = -1;
	else if (keycode == 123)
		all->plr.rttn = 1;
	return (1);
}

int		key_release(int keycode, t_cub *all)
{
	if (keycode == 13)
		all->plr.bttn_w = 0;
	else if (keycode == 0)
		all->plr.bttn_a = 0;
	else if (keycode == 1)
		all->plr.bttn_s = 0;
	else if (keycode == 2)
		all->plr.bttn_d = 0;
	if (keycode == 124 || keycode == 123)
		all->plr.rttn = 0;
	return (1);
}

void	rotation(t_cub *all)
{
	double	old_dr_x;
	double	old_pln_x;
	double	rotate;

	old_dr_x = all->plr.drctn_x;
	old_pln_x = all->plr.pln_x;
	rotate = all->plr.rttn_spd * all->plr.rttn;
	all->plr.drctn_x = all->plr.drctn_x * cos(rotate) - all->plr.drctn_y
	* sin(rotate);
	all->plr.drctn_y = old_dr_x * sin(rotate) + all->plr.drctn_y * cos(rotate);
	all->plr.pln_x = all->plr.pln_x * cos(rotate) - all->plr.pln_y
	* sin(rotate);
	all->plr.pln_y = old_pln_x * sin(rotate) + all->plr.pln_y * cos(rotate);
}

void	move_ws(t_cub *all)
{
	if (all->plr.bttn_w)
	{
		if (all->map[(int)(all->plr.pstn_x + all->plr.drctn_x * all->plr.spd)]
		[(int)all->plr.pstn_y] == '0')
			all->plr.pstn_x += all->plr.drctn_x * all->plr.spd;
		if (all->map[(int)all->plr.pstn_x]
		[(int)(all->plr.pstn_y + all->plr.drctn_y * all->plr.spd)] == '0')
			all->plr.pstn_y += all->plr.drctn_y * all->plr.spd;
	}
	if (all->plr.bttn_s)
	{
		if (all->map[(int)(all->plr.pstn_x - all->plr.drctn_x * all->plr.spd)]
		[(int)all->plr.pstn_y] == '0')
			all->plr.pstn_x -= all->plr.drctn_x * all->plr.spd;
		if (all->map[(int)all->plr.pstn_x]
		[(int)(all->plr.pstn_y - all->plr.drctn_y * all->plr.spd)] == '0')
			all->plr.pstn_y -= all->plr.drctn_y * all->plr.spd;
	}
}

void	move_ad(t_cub *all)
{
	if (all->plr.bttn_a)
	{
		if (all->map[(int)(all->plr.pstn_x - all->plr.drctn_y * all->plr.spd)]
		[(int)all->plr.pstn_y] == '0')
			all->plr.pstn_x -= all->plr.drctn_y * all->plr.spd;
		if (all->map[(int)all->plr.pstn_x]
		[(int)(all->plr.pstn_y + all->plr.drctn_x * all->plr.spd)] == '0')
			all->plr.pstn_y += all->plr.drctn_x * all->plr.spd;
	}
	if (all->plr.bttn_d)
	{
		if (all->map[(int)(all->plr.pstn_x + all->plr.drctn_y * all->plr.spd)]
		[(int)all->plr.pstn_y] == '0')
			all->plr.pstn_x += all->plr.drctn_y * all->plr.spd;
		if (all->map[(int)all->plr.pstn_x]
		[(int)(all->plr.pstn_y - all->plr.drctn_x * all->plr.spd)] == '0')
			all->plr.pstn_y -= all->plr.drctn_x * all->plr.spd;
	}
}
