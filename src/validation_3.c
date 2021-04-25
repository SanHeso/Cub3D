/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:41:14 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/25 16:49:40 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_comma(char *arr)
{
	int		i;
	int		u;

	i = 0;
	u = 0;
	while (arr[i])
	{
		if (arr[i] == ',')
			u++;
		i++;
	}
	if (u == 2)
		return (1);
	end_of_prog(NO_COLOR);
	return (0);
}
