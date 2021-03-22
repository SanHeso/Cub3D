/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils(2).c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:19:23 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/20 17:03:54 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		close_prog(int keycode, t_cub *all)
{
	exit(0);
	return (0);
}

int		ch_arg(int *arr)
{
	if (arr[0], arr[1], !arr[2])
		return (1);
	return (0);
}
