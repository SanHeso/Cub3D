/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:32:38 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/17 19:08:21 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	valid_cart(t_cub *all, int x, int y)
{
	if (all->map[y][x] > ft_strlen(all->map[y]) ||
	all->map[y][x] > ft_strlen(all->map[y + 1]) ||
	all->map[y][x] > ft_strlen(all->map[y - 1]))
		end_of_prog();
	if (x < 1 || y < 1)
		end_of_prog();
	if (!ft_strchr("012NSEW", all->map[y][x]))
		end_of_prog();
	if (!ft_strchr("012NSEW", all->map[y][x + 1]))
		end_of_prog();
	if (!ft_strchr("012NSEW", all->map[y][x - 1]))
		end_of_prog();
	if (!ft_strchr("012NSEW", all->map[y + 1][x]))
		end_of_prog();
	if (!ft_strchr("012NSEW", all->map[y - 1][x]))
		end_of_prog();
	if (all->map[y][0] == '\0')
		end_of_prog();
}

void	valid_screen_size(t_cub *all, char **arr)
{
	int		i;

	i = 0;
	if (all->pars.w)
	{
		while (!ft_isdigit(arr[1][i++]))
			end_of_prog();
		all->pars.h = mod_atoi(arr[1]);
	}
	i = 0;
	if (all->pars.h)
	{
		while (!ft_isdigit(arr[2][i++]))
			end_of_prog();
		all->pars.h = mod_atoi(arr[2]);
	}
}

void	real_screen_size(t_cub *all)
{
	int		rw;
	int		rh;

	mlx_get_screen_size(&rw, &rh);
	// if()
}
