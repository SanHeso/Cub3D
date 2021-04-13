/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:32:38 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/13 17:04:48 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	valid_cart(t_cub *all, int y, int x)
{
	if (!ft_strchr("012NSEW", all->map[y][x]))
		end_of_prog(NO_MAP);
	if (!ft_strchr("012NSEW", all->map[y][x + 1]))
		end_of_prog(NO_MAP);
	if (!ft_strchr("012NSEW", all->map[y][x - 1]))
		end_of_prog(NO_MAP);
	if (!ft_strchr("012NSEW", all->map[y + 1][x]))
		end_of_prog(NO_MAP);
	if (!ft_strchr("012NSEW", all->map[y - 1][x]))
		end_of_prog(NO_MAP);
	if (!ft_strchr("012NSEW", all->map[y - 1][x + 1]))
		end_of_prog(NO_MAP);
	if (!ft_strchr("012NSEW", all->map[y + 1][x + 1]))
		end_of_prog(NO_MAP);
	if (!ft_strchr("012NSEW", all->map[y - 1][x - 1]))
		end_of_prog(NO_MAP);
	if (!ft_strchr("012NSEW", all->map[y + 1][x - 1]))
		end_of_prog(NO_MAP);
	if (x > ft_strlen(all->map[y]) || x > ft_strlen(all->map[y + 1]) ||
	x > ft_strlen(all->map[y - 1]))
		end_of_prog(NO_MAP);
	if (x < 1 || y < 1)
		end_of_prog(NO_MAP);
}

void	valid_screen_size(t_cub *all, char **arr)
{
	int		i;

	i = 0;
	if (all->pars.w)
	{
		while (!ft_isdigit(arr[1][i++]))
			end_of_prog(RESOLUTION);
		all->pars.h = mod_atoi(arr[1]);
	}
	i = 0;
	if (all->pars.h)
	{
		while (!ft_isdigit(arr[2][i++]))
			end_of_prog(RESOLUTION);
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

	i = 0;
	tmp = ft_split(arr, ',');
	while (ch == 'F' && i < 3)
	{
		all->pars.f[i] = ft_atoi(tmp[i]);
		if (all->pars.f[i] > 255)
			end_of_prog(NO_COLOR);
		free(tmp[i]);
		i++;
	}
	while (ch == 'C' && i < 3)
	{
		all->pars.c[i] = (float)ft_atoi(tmp[i]);
		if (all->pars.c[i] > 255)
			end_of_prog(NO_COLOR);
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
		end_of_prog(NO_ARG);
	if (i < 4 || ft_strncmp(&argv[1][i - 4], ".cub", 4))
		end_of_prog(FILE);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
		end_of_prog(FLAG);
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		all->scrn_sht = 1;
}

void	validate(t_cub *all)
{
	int		i;
	int		j;

	i = -1;
	while (all->map[++i])
	{
		if (all->map[i][0] == '\0')
			end_of_prog(NO_MAP);
		j = -1;
		while (all->map[i][++j])
		{
			if (ft_strchr("02NSWE", all->map[i][j]))
				valid_cart(all, i, j);
			if (ft_strchr("NSWE", all->map[i][j]))
			{
				if (all->plr.pstn_x != -1)
					end_of_prog(MORE_PLR);
				drctn_plr(all, all->map[i][j]);
				all->map[i][j] = '0';
				all->plr.pstn_x = i + 0.45;
				all->plr.pstn_y = j + 0.45;
			}
		}
	}
	if (all->plr.pln_x == -1)
		end_of_prog(NO_PLR);
}
