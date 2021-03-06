/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:01:19 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/25 16:49:05 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	sprite(t_cub *all, double *zbuf, int *sp_order, int x)
{
	x = -1;
	while (++x < all->sp_count)
	{
		sp_pos(all, sp_order, x);
		sp_height_width(all);
		sp_draw(all, zbuf);
	}
}

void	assembly(t_cub *all)
{
	int		x;
	int		sp_order[all->sp_count];
	double	zbuf[all->pars.w];
	double	sp_dist[all->sp_count];

	x = -1;
	while (x++ < all->pars.w)
	{
		init_ray(all, x);
		step(all);
		alg_dda(&all->dda, all->map);
		fish_eye(&all->dda, &all->plr);
		height_wall(&all->dda, &all->pars);
		wall_hit(all);
		texture(all);
		draw_wall(all, x, all->dda.draw_start - 1);
		ceil_floor(all, x);
		zbuf[x] = all->dda.prp_wll_dst;
	}
	sp_distant(all, sp_dist, sp_order);
	sprite(all, zbuf, sp_order, x);
}

int		paint(t_cub *all)
{
	move_ws(all);
	move_ad(all);
	rotation(all);
	assembly(all);
	if (all->screenshot)
		screenshot(all, "Screen");
	mlx_clear_window(all->win.mlx, all->win.win);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->win.img, 0, 0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_cub	all;

	init_pars(&all);
	valid_arg(&all, argc, argv);
	if ((all.pars.fd = open(argv[1], O_RDONLY)) == -1)
		end_of_prog(NO_DIR);
	init_player(&all);
	parser(&all);
	all.win.mlx = mlx_init();
	all.win.img = mlx_new_image(all.win.mlx, all.pars.w, all.pars.h);
	all.win.adrs = mlx_get_data_addr(all.win.img, &all.win.bpp, &all.win.len,
	&all.win.end);
	all.win.win = mlx_new_window(all.win.mlx, all.pars.w, all.pars.h, "first");
	if (!all.screenshot)
	{
		mlx_hook(all.win.win, 2, 1L << 0, key_press, &all);
		mlx_hook(all.win.win, 3, 1L << 1, key_release, &all);
		mlx_hook(all.win.win, 17, 1L << 0, close_prog, &all);
	}
	mlx_loop_hook(all.win.mlx, &paint, &all);
	mlx_loop(all.win.mlx);
}
