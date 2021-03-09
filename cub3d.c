/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:01:19 by hnewman           #+#    #+#             */
/*   Updated: 2021/02/08 17:29:29 by hnewman          ###   ########.fr       */
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
	while (yp < 10)
	{
		xp = 0;
		while (xp < 10)
		{
			ft_mlx_pixel_put(data, xp + x, yp + y, 0x0000FF00);
			xp++;
		}
		yp++;
	}
}

int		main(void)
{
	void	*mlx;
	void	*win;
	t_pix	pix;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1280, 720, "first");
	pix.img = mlx_new_image(mlx, 1280, 720);
	pix.adrs = mlx_get_data_addr(pix.img, &pix.bits, &pix.len, &pix.end);
	
	block(&pix, 15, 15);
	mlx_put_image_to_window(mlx, win, pix.img, 10, 10);
	mlx_loop(mlx);
}
