/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:40:22 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/12 19:33:54 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	real_screen_size(t_cub *all)
{
	int		rw;
	int		rh;

	mlx_get_screen_size(&rw, &rh);
	if (all->pars.h > rh)
		all->pars.h = rh;
	if (all->pars.w > rw)
		all->pars.w = rw;
}

void	drctn_plr(t_cub *all, int ch)
{
	if (ch == 'N')
	{
		all->plr.drctn_x = -1;
		all->plr.pln_y = 0.66;
	}
	if (ch == 'S')
	{
		all->plr.drctn_x = 1;
		all->plr.pln_y = -0.66;
	}
	if (ch == 'W')
	{
		all->plr.drctn_y = -1;
		all->plr.pln_x = -0.66;
	}
	if (ch == 'E')
	{
		all->plr.drctn_y = 1;
		all->plr.pln_x = 0.66;
	}
}

void	valid_texture(t_win *tex, char **mas, char **root)
{
	tex->mlx = mlx_init();
	*root = ft_strdup(mas[1]);
	if (!(tex->img = mlx_xpm_file_to_image(&tex->mlx, *root, tex->t_wdth,
	tex->t_hght)))
		end_of_prog(NO_TEX);
	tex->adrs = mlx_get_data_addr(tex->img, &tex->bpp, tex->len, tex->end);
}