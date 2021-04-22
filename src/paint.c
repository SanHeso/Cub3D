/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:52:08 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/22 16:08:15 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_mlx_pixel_put(t_win *data, int x, int y, int col)
{
	char	*dest;

	dest = data->adrs + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dest = col;
}

int		rgb(int arr[3])
{
	return (arr[0] << 16 | arr[1] << 8 | arr[2]);
}

int		ft_mlx_pixel_get(t_win *data, int x, int y)
{
	char	*dest;
	int		col;

	dest = data->adrs + (y * data->len + x * (data->bpp / 8));
	col = *(unsigned int *)dest;
	return (col);
}

void	draw_wall(t_cub *all, int x, int y)
{
	while (++y < all->dda.draw_end)
	{
		all->dda.tex_y = (int)all->dda.tex_pstn;
		all->dda.tex_pstn += all->dda.step;
		if (all->dda.side == 1)
		{
			if (all->dda.stp_y > 0)
				all->dda.col = ft_mlx_pixel_get(&all->ea, all->dda.tex_x,
				all->dda.tex_y);
			if (all->dda.stp_y < 0)
				all->dda.col = ft_mlx_pixel_get(&all->we, all->dda.tex_x,
				all->dda.tex_y);
		}
		else
		{
			if (all->dda.stp_x > 0)
				all->dda.col = ft_mlx_pixel_get(&all->no, all->dda.tex_x,
				all->dda.tex_y);
			 if (all->dda.stp_x < 0)
				all->dda.col = ft_mlx_pixel_get(&all->so, all->dda.tex_x,
				all->dda.tex_y);
		}
		ft_mlx_pixel_put(&all->win, x, y, all->dda.col);
	}
}

void	ceil_floor(t_cub *all, int x)
{
	int		y;

	y = -1;
	if (all->pars.f[0] == -1 || all->pars.c[0] == -1)
		end_of_prog(NO_PARAM);
	while (++y < all->dda.draw_start)
		ft_mlx_pixel_put(&all->win, x, y, rgb(all->pars.c));
	y = all->dda.draw_end - 1;
	while (++y < all->pars.h - 1)
		ft_mlx_pixel_put(&all->win, x, y, rgb(all->pars.f));
}
