/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:50:57 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/14 19:59:08 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	order_sort(order, qua);
	i = -1;
	while (++i < qua)
	{
		dist[i] = sp[qua - i - 1].first;
		order[i] = sp[qua - i - 1].second;
	}
	free(sp);
}

void	sp_dist(t_cub *all, double *sp_dist, int *sp_ord)
{
	int		i;

	i = -1;
	while (++i < all->sp_count)
	{
		sp_ord[i] = i;
		sp_dist[i] = ((all->plr.pstn_x - all->sp[i].x)
					* (all->plr.pstn_x - all->sp[i].x)
					+ (all->plr.pstn_y - all->sp[i].x)
					* (all->plr.pstn_y - all->sp[i].x))
	}
	sp_sort(sp_dist, sp_ord, all->sp_count);
}