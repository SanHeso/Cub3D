/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:32:38 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/22 17:48:06 by hnewman          ###   ########.fr       */
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
	real_screen_size(all);
	if (all->pars.w == 0 || all->pars == 0)
		end_of_prog();
}

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

void	valid_flo_cei(t_cub *all, char *arr)
{
	char	**tmp;

	i = 0;
	tmp = ft_split(arr, ',');
	while (ch == 'F' && i < 3)
	{
		if (!ft_isdigit(tmp[i]))
			end_of_prog();
		all->pars.f[i] = (float)ft_atoi(tmp[i]);
		if (all->pars.f[i] > 255)
			end_of_prog();
		free(tmp[i]);
		i++;
	}
	while (ch == 'C' && i < 3)
	{
		if (!ft_isdigit(tmp[i]))
			end_of_prog();
		all->pars.c[i] = (float)ft_atoi(tmp[i]);
		if (all->pars.c[i] > 255)
			end_of_prog();
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	valid_arg(t_cub *all, int argc, char **argv)
{
	int		i;

	i = ft_strlen(argv[1]);
	if (argc < 2 || argc > 3)
		end_of_prog();
	if (i < 4 || ft_strncmp(argv[1], ".cub", 4))
		end_of_prog();
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
		end_of_prog();
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		all->scrn_sht = 1;
}
