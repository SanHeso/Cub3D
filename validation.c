/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:32:38 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/16 18:14:43 by hnewman          ###   ########.fr       */
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

