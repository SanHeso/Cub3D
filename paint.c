/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:52:08 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/23 20:03:41 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_pixel_put(t_pix *data, int x, int y, int col)
{
	char	*dest;

	dest = data->adrs + (y * data->len + x * (data->bits / 8));
	*(unsigned int *)dest = col;
}

void	block(t_pix *data, int x, int y)
{
	int xp;
	int yp;

	yp = 0;
	while (yp < SCALE)
	{
		xp = 0;
		while (xp < SCALE)
		{
			ft_mlx_pixel_put(data, xp + x, yp + y, 0x0000FF00);
			xp++;
		}
		yp++;
	}
}
