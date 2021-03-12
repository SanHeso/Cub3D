/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:32:38 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/12 20:11:42 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	valid_cart(t_cub *all, int x, int y)
{
	if (all->map[y][x] > ft_strlen(all->map[y]) ||
	all->map[y][x] > ft_strlen(all->map[y + 1]) ||
	all->map[y][x] > ft_strlen(all->map[y - 1]))
		end_of_prog();
	if (all->map[y][x] != '0' || all->map[y][x] != '1' || all->map[y][x] != '2'
	|| all->map[y][x] != 'N' || all->map[y][x] != 'S' || all->map[y][x] != 'W'
	|| all->map[y][x] != 'E')
		end_of_prog();
	if (all->map[y][x + 1] != '0' || all->map[y][x + 1] != '1'
	|| all->map[y][x + 1] != '2' || all->map[y][x + 1] != 'N'
	|| all->map[y][x + 1] != 'S' || all->map[y][x + 1] != 'W'
	|| all->map[y][x + 1] != 'E')
		end_of_prog();
	if (all->map[y][x - 1] != '0' || all->map[y][x - 1] != '1'
	|| all->map[y][x - 1] != '2' || all->map[y][x - 1] != 'N'
	|| all->map[y][x - 1] != 'S' || all->map[y][x - 1] != 'W'
	|| all->map[y][x - 1] != 'E')
		end_of_prog();
	if (all->map[y + 1][x] != '0' || all->map[y + 1][x] != '1'
	|| all->map[y + 1][x] != '2' || all->map[y + 1][x] != 'N'
	|| all->map[y + 1][x] != 'S' || all->map[y + 1][x] != 'W'
	|| all->map[y + 1][x] != 'E')
		end_of_prog();
	if (all->map[y - 1][x] != '0' || all->map[y - 1][x] != '1'
	|| all->map[y - 1][x] != '2' || all->map[y - 1][x] != 'N'
	|| all->map[y - 1][x] != 'S' || all->map[y - 1][x] != 'W'
	|| all->map[y - 1][x] != 'E')
		end_of_prog();
}
