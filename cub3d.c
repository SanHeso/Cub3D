/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:01:19 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/29 20:08:46 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assembly(t_cub *all)
{
	int		x;
	double	buf[all->pars.w];

	x = -1;
	while (x++ < all->pars.w)
	{
		init_ray(all, x);
		step(all);
		dda(&all->dda, all->map);
		fish_eye(&all->dda, &all->plr);
		height_wall(&all->dda, &all->pars);
		wall(all, x);
		ceil_floor(all, x);
		buf[x] = all->dda.prp_wll_dst;
	}
}

int		paint(t_cub *all)
{
	move_ws(all);
	move_ad(all);
	rotation(all);
	assembly(all);
	mlx_clear_window(all->win.mlx, all->win.win);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->win.img, 0, 0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_win	win;
	t_cub	all;

	init_pars(&all);
	valid_arg(&all, argc, argv);
	if ((all.pars.fd = open(argv[1], O_RDONLY)) == -1)
		end_of_prog();
	init_player(&all);
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
