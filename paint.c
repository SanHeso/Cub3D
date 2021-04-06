/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:52:08 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/05 18:29:05 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	wall(t_cub *all, int x)
{
	while (all->dda.draw_start < all->dda.draw_end)
	{
		ft_mlx_pixel_put(&all->win, x, all->dda.draw_start, 0xFF9100);
		all->dda.draw_start++;
	}
}

void	ceil_floor(t_cub *all, int x)
{
	int		y;

	y = -1;
	while (++y < all->dda.draw_start)
		ft_mlx_pixel_put(&all->win, x, all->dda.draw_start, 0x24A6C9);
	y = all->dda.draw_end - 1;
	while (++y < all->pars.h - 1)
		ft_mlx_pixel_put(&all->win, x, all->dda.draw_start, 0x00FF00);
}

// void	block(t_pix *data, int x, int y)
// {
// 	int xp;
// 	int yp;

// 	yp = 0;
// 	while (yp < SCALE)
// 	{
// 		xp = 0;
// 		while (xp < SCALE)
// 		{
// 			ft_mlx_pixel_put(data, xp + x, yp + y, 0x0000FF00);
// 			xp++;
// 		}
// 		yp++;
// 	}
// }
