/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:40:22 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/25 16:48:01 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	if (!(tex->img = mlx_xpm_file_to_image(&tex->mlx, *root, &tex->t_wdth,
	&tex->t_hght)))
		end_of_prog(NO_TEX);
	tex->adrs = mlx_get_data_addr(tex->img, &tex->bpp, &tex->len, &tex->end);
}

void	sp_sum(t_cub *all)
{
	int		i;
	int		j;

	i = -1;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == '2')
				all->sp_count++;
		}
	}
	if (!(all->sp = malloc(sizeof(t_sp *) * all->sp_count)))
		end_of_prog(NO_MAL);
}

void	pos_sp_plr(t_cub *all, int i, int j)
{
	static int	count;

	if (!count)
		count = 0;
	if (ft_strchr("NSWE", all->map[i][j]))
	{
		if (all->plr.pstn_x != -1)
			end_of_prog(MORE_PLR);
		drctn_plr(all, all->map[i][j]);
		all->map[i][j] = '0';
		all->plr.pstn_x = i + 0.5;
		all->plr.pstn_y = j + 0.5;
	}
	if (all->map[i][j] == '2')
	{
		all->sp[count].x = i + 0.5;
		all->sp[count].y = j + 0.5;
		count++;
	}
}
