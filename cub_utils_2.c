/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:19:23 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/09 16:02:02 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	memfree(char ***arr)
{
	int		i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	free((*arr));
}

int		close_prog(int keycode)
{
	keycode = 0;
	exit(0);
	return (1);
}

int		ch_arg(char **arr)
{
	if (arr[0] && arr[1] && !arr[2])
		return (1);
	return (0);
}

int		transit_to_map(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '1')
	{
		if (line[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

