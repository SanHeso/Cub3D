/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:24:14 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/01 13:56:25 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_pars(t_cub *all)
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

void	init_ray(t_cub *all, int x)
{
	all->dda.cmr_x = 2 * x / (double)all->pars.w - 1;
	all->dda.r_dr_x = all->plr.drctn_x + all->plr.pln_x * all->dda.cmr_x;
	all->dda.r_dr_y = all->plr.drctn_y + all->plr.pln_y * all->dda.cmr_x;
	all->dda.map_x = (int)all->plr.pstn_x;
	all->dda.map_y = (int)all->plr.pstn_y;
	all->dda.dlt_dst_x = fabs(1 / all->dda.r_dr_x);
	all->dda.dlt_dst_y = fabs(1 / all->dda.r_dr_y);
	all->dda.hit = 0;
}

void	init_player(t_cub *all)
{
	all->plr.pstn_x = -1;
	all->plr.pstn_x = -1;
	all->plr.bttn_w = 0;
	all->plr.bttn_a = 0;
	all->plr.bttn_s = 0;
	all->plr.bttn_d = 0;
	all->plr.rttn = 0;
	all->plr.rttn_spd = 3.0;
	all->plr.spd = 5.0;
}

void	end_of_prog(char *s)
{
	write(1, s, ft_strlen(s));
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
		end_of_prog(MATH);
	while (str[i] >= '0' && str[i] <= '9')
	{
		u = u * 10 + (str[i] - '0');
		i++;
	}
	if (u > 99999)
		return (99999);
	return (u);
}
