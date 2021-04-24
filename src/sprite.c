/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:50:57 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/24 16:07:37 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	sp_sort(double *dist, int *order, int qua)
{
	t_sort	*sp;
	int		i;

	i = -1;
	if (!(sp = (t_sort *)malloc(sizeof(t_sort) * qua)))
		end_of_prog(NO_MAL);
	while (++i < qua)
	{
		sp[i].first = dist[i];
		sp[i].second = order[i];
	}
	order_sort(sp, qua);
	i = -1;
	while (++i < qua)
	{
		dist[i] = sp[qua - i - 1].first;
		order[i] = sp[qua - i - 1].second;
	}
	free(sp);
}

void	sp_distant(t_cub *all, double *sp_dist, int *sp_ord)
{
	int		i;

	i = -1;
	while (++i < all->sp_count)
	{
		sp_ord[i] = i;
		sp_dist[i] = ((all->plr.pstn_x - all->sp[i].x)
					* (all->plr.pstn_x - all->sp[i].x)
					+ (all->plr.pstn_y - all->sp[i].y)
					* (all->plr.pstn_y - all->sp[i].y));
	}
	sp_sort(sp_dist, sp_ord, all->sp_count);
}

void	sp_pos(t_cub *all, int *sp_ord, int i)
{
	all->dda.sp_x = all->sp[sp_ord[i]].x - all->plr.pstn_x;
	all->dda.sp_y = all->sp[sp_ord[i]].y - all->plr.pstn_y;
	all->dda.inv_det = 1.0 / (all->plr.pln_x * all->plr.drctn_y
		- all->plr.drctn_x * all->plr.pln_y);
	all->dda.tr_form_x = all->dda.inv_det * (all->plr.drctn_y * all->dda.sp_x
		- all->plr.drctn_x * all->dda.sp_y);
	all->dda.tr_form_y = all->dda.inv_det * (-all->plr.pln_y * all->dda.sp_x
		+ all->plr.pln_x * all->dda.sp_y);
	all->dda.sp_scrn_x = (int)((all->pars.w / 2) * (1 + all->dda.tr_form_x
		/ all->dda.tr_form_y));
}

void	sp_height_width(t_cub *all)
{
	all->dda.sp_h = abs((int)(all->pars.h / all->dda.tr_form_y));
	all->dda.draw_start_y = -all->dda.sp_h / 2 + all->pars.h / 2;
	if (all->dda.draw_start_y < 0)
		all->dda.draw_start_y = 0;
	all->dda.draw_end_y = all->dda.sp_h / 2 + all->pars.h / 2;
	if (all->dda.draw_end_y >= all->pars.h)
		all->dda.draw_end_y = all->pars.h - 1;
	all->dda.sp_w = abs((int)(all->pars.w / all->dda.tr_form_y) / 2);
	all->dda.draw_start_x = -all->dda.sp_w / 2 + all->dda.sp_scrn_x;
	if (all->dda.draw_start_x < 0)
		all->dda.draw_start_x = 0;
	all->dda.draw_end_x = all->dda.sp_w / 2 + all->dda.sp_scrn_x;
	if (all->dda.draw_end_x >= all->pars.w)
		all->dda.draw_end_x = all->pars.w - 1;
}

void	sp_draw(t_cub *all, double *zbuf)
{
	int		i;
	int		j;
	int		tmp;

	i = all->dda.draw_start_x - 1;
	while (++i < all->dda.draw_end_x)
	{
		j = all->dda.draw_start_y - 1;
		all->dda.tex_x = (int)(256 * (i - (-all->dda.sp_w / 2 +
			all->dda.sp_scrn_x)) * all->s.t_wdth / all->dda.sp_w) / 256;
		if (all->dda.tr_form_y > 0 && i > 0 && i < all->pars.w &&
			all->dda.tr_form_y < zbuf[i])
		{
			while (++j < all->dda.draw_end_y)
			{
				tmp = (j) * 256 - all->pars.h * 128 + all->dda.sp_h * 128;
				all->dda.tex_y = ((tmp * all->s.t_hght) / all->dda.sp_h) / 256;
				all->dda.col = ft_mlx_pixel_get(&all->s, all->dda.tex_x,
					all->dda.tex_y);
				if ((all->dda.col & 0x00FFFFFF) != 0)
					ft_mlx_pixel_put(&all->win, i, j, all->dda.col);
			}
		}
	}
}