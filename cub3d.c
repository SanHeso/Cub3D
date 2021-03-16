/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:01:19 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/16 19:25:55 by hnewman          ###   ########.fr       */
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

// int		paint(t_cub *all)
// {

// }

int		main(int argc, char **argv)
{
	t_pix	pix;
	t_cub	all;
	
	newcub(&all);
	if ((all.pars.fd = open(argv[1], O_RDONLY)) == -1)
		end_of_prog();
	parser(&all);

	all.win.mlx = mlx_init();
	all.win.win = mlx_new_window(all.win.mlx, all.pars.w, all.pars.h, "first");
	pix.img = mlx_new_image(all.win.mlx, all.pars.w, all.pars.h);
	pix.adrs = mlx_get_data_addr(pix.img, &pix.bits, &pix.len, &pix.end);
	mlx_hook(all.win.win, 2, 1L << 0, key_press, &all);
	mlx_hook(all.win.win, 3, 1L << 1, key_release, &all);
	mlx_hook(all.win.win, 2, 1L << 0, close, &all);
	//mlx_put_image_to_window(all.win.mlx, all.win.win, pix.img, 10, 10);
	//mlx_loop_hook(all.win.mlx, paint, &all);
	mlx_loop(all.win.mlx);
	return (argc);
}
