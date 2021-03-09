/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:24:14 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/09 20:28:58 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	newcub(t_cub *all)
{
	all->pars.heightr = 0;
	all->pars.widthr = 0;
	all->pars.NO = 0;
	all->pars.SO = 0;
	all->pars.WE = 0;
	all->pars.EA = 0;
	all->pars.S = 0;
	all->pars.F[3] = 0;
	all->pars.C[3] = 0;
}
