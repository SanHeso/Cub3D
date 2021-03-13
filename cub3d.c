/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:01:19 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/13 20:06:28 by hnewman          ###   ########.fr       */
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

int		main(void)
{
	void	*mlx;
	void	*win;
	int		y = 0;
	int		x = 0;
	t_pix	pix;
	t_cub	all;

	newcub(&all);
	if ((all.pars.fd = open("defcart.cub", O_RDONLY)) == -1)
		end_of_prog();
	parser(&all);

	// while(1)
	// {}

	mlx = mlx_init();
	win = mlx_new_window(mlx, all.pars.widr, all.pars.heir, "first");
	pix.img = mlx_new_image(mlx, all.pars.widr, all.pars.heir);
	pix.adrs = mlx_get_data_addr(pix.img, &pix.bits, &pix.len, &pix.end);

	block(&pix, 15, 15);
	mlx_put_image_to_window(mlx, win, pix.img, 10, 10);
	mlx_loop(mlx);
}
