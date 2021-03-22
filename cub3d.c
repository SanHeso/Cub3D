/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:01:19 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/22 19:50:11 by hnewman          ###   ########.fr       */
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

void	assembly(t_cub *all)
{
	int		x;

}

int		paint(t_cub *all)
{
	move_ws(all);
	move_ad(all);
	rotation(all);
	mlx_clear_window(all->win.mlx, all->win.win);
	mlx_put_image_to_window((all->win.mlx, all->win.win, all->win.img, 0, 0));
}

int		main(int argc, char **argv)
{
	t_win	win;
	t_cub	all;

	init_pars(&all);
	valid_arg(&all, argc, argv);
	if ((all.pars.fd = open(argv[1], O_RDONLY)) == -1)
		end_of_prog();
	parser(&all);

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, all.pars.w, all.pars.h, "first");
	win.img = mlx_new_image(win.mlx, all.pars.w, all.pars.h);
	win.adrs = mlx_get_data_addr(win.img, &win.bpp, &win.len, &win.end);
	mlx_hook(win.win, 2, 1L << 0, key_press, &all);
	mlx_hook(win.win, 3, 1L << 1, key_release, &all);
	mlx_hook(win.win, 2, 1L << 0, close_prog, &all);
	//mlx_put_image_to_window(win.mlx, win.win, win.img, 10, 10);
	//mlx_loop_hook(win.mlx, paint, &all);
	mlx_loop(win.mlx);
	return (argc);
}
