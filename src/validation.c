/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:32:38 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/25 16:56:53 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	valid_cart(t_cub *all, int y, int x, int size)
{
	if (x < 1 || y < 1 || y == size - 1)
		end_of_prog(NO_MAP);
	if (!all->map[y][x + 1] || !ft_strchr("012NSEW", all->map[y][x + 1]))
		end_of_prog(NO_MAP);
	if (!ft_strchr("012NSEW", all->map[y][x - 1]))
		end_of_prog(NO_MAP);
	if (!all->map[y - 1][x + 1] || !ft_strchr("012NSEW",
	all->map[y - 1][x + 1]))
		end_of_prog(NO_MAP);
	if (!all->map[y + 1][x + 1] || !ft_strchr("012NSEW",
	all->map[y + 1][x + 1]))
		end_of_prog(NO_MAP);
	if (!ft_strchr("012NSEW", all->map[y + 1][x]))
		end_of_prog(NO_MAP);
	if (!ft_strchr("012NSEW", all->map[y - 1][x]))
		end_of_prog(NO_MAP);
	if (!ft_strchr("012NSEW", all->map[y - 1][x - 1]))
		end_of_prog(NO_MAP);
	if (!ft_strchr("012NSEW", all->map[y + 1][x - 1]))
		end_of_prog(NO_MAP);
}

void	valid_screen_size(t_cub *all, char **arr)
{
	int		i;

	i = -1;
	if (!all->pars.w)
	{
		while (arr[1][++i])
		{
			if (!ft_isdigit(arr[1][i]))
				end_of_prog(RESOLUTION);
		}
		all->pars.w = mod_atoi(arr[1]);
	}
	i = 0;
	if (!all->pars.h)
	{
		while (arr[2][++i])
		{
			if (!ft_isdigit(arr[2][i]))
				end_of_prog(RESOLUTION);
		}
		all->pars.h = mod_atoi(arr[2]);
	}
	real_screen_size(all);
	if (all->pars.w == 0 || all->pars.h == 0)
		end_of_prog(RESOLUTION);
}

void	valid_flo_cei(t_cub *all, char *arr, int ch)
{
	char	**tmp;
	int		i;

	i = -1;
	if (check_comma(arr))
		tmp = ft_split(arr, ',');
	while (ch == 'F' && ++i < 3)
	{
		if (!tmp[i])
			end_of_prog(NO_COLOR);
		all->pars.f[i] = mod_atoi(tmp[i]);
		if (all->pars.f[i] > 255)
			end_of_prog(NO_COLOR);
		free(tmp[i]);
	}
	while (ch == 'C' && ++i < 3)
	{
		if (!tmp[i])
			end_of_prog(NO_COLOR);
		all->pars.c[i] = mod_atoi(tmp[i]);
		if (all->pars.c[i] > 255)
			end_of_prog(NO_COLOR);
		free(tmp[i]);
	}
	free(tmp);
}

void	valid_arg(t_cub *all, int argc, char **argv)
{
	int		i;

	if (argc < 2 || argc > 3)
		end_of_prog(NO_ARG);
	i = ft_strlen(argv[1]);
	if (i < 4 || ft_strncmp(&argv[1][i - 4], ".cub", 4))
		end_of_prog(FILE);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
		end_of_prog(FLAG);
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 7))
		all->screenshot = 1;
}

void	validate(t_cub *all, int size)
{
	int		i;
	int		j;

	i = -1;
	sp_sum(all);
	while (all->map[++i])
	{
		if (all->map[i][0] == '\0')
			end_of_prog(NO_MAP);
		j = -1;
		while (all->map[i][++j])
		{
			if (ft_strchr("02NSWE", all->map[i][j]))
				valid_cart(all, i, j, size);
			pos_sp_plr(all, i, j);
		}
	}
	if (all->plr.pstn_x == -1)
		end_of_prog(NO_PLR);
}
