/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:58:06 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/16 19:55:45 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int keycode, t_cub *all)
{
	if (keycode == 13)
		all->plr.bttnW = 1;
	else if (keycode == 0)
		all->plr.bttnA = 1;
	else if (keycode == 1)
		all->plr.bttnS = 1;
	else if (keycode == 2)
		all->plr.bttnD = 1;
	else if (keycode == 53)
		exit(0);
	if (keycode == 124)
		all->plr.rttn = -1;
	else if (keycode == 123)
		all->plr.rttn = 1;
	// if (keycode)
	// 	ft_putnbr_fd(keycode, 1);
	return (1);
}

int		key_release(int keycode, t_cub *all)
{
	if (keycode == 13)
		all->plr.bttnW = 0;
	else if (keycode == 0)
		all->plr.bttnA = 0;
	else if (keycode == 1)
		all->plr.bttnS = 0;
	else if (keycode == 2)
		all->plr.bttnD = 0;
	if (keycode == 124 || keycode == 123)
		all->plr.rttn = 0;
	// if (keycode)
	// 	ft_putnbr_fd(keycode, 1);
	return (1);
}

int		close(int keycode, t_cub *all)
{
	exit(0);
	return (0);
}

void	move_ws(t_cub *all)
{
	if (all->plr.bttn_w)
	{
		if (all->map[(int)all->plr.pstn_x + all->plr.drctn_x * all->plr.spd]
		[(int)all->plr.pstn_y])
			all->plr.pstn_x += all->plr.drctn_x * all->plr.spd;
		if (all->map[(int)all->plr.pstn_x]
		[(int)all->plr.pstn_y + all->plr.drctn_y * all->plr.spd])
			all->plr.pstn_y += all->plr.drctn_y * all->plr.spd;
	}
	if (all->plr.bttn_s)
	{
		if (all->map[(int)all->plr.pstn_x - all->plr.drctn_x * all->plr.spd]
		[(int)all->plr.pstn_y])
			all->plr.pstn_x -= all->plr.drctn_x * all->plr.spd;
		if (all->map[(int)all->plr.pstn_x]
		[(int)all->plr.pstn_y - all->plr.drctn_y * all->plr.spd])
			all->plr.pstn_y -= all->plr.drctn_y * all->plr.spd;
	}
}

void	move_ad(t_cub *all)
{
	
}
