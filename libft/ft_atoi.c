/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:10:39 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/22 15:01:50 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		skip(char *str, int i)
{
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' \
	|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int i;
	int s;
	int u;

	i = 0;
	u = 0;
	s = 0;
	if (!str)
		return (-1);
	skip(str, i);
	if (str[i] == '-')
	{
		s++;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		u = u * 10 + (str[i] - '0');
		i++;
	}
	if (s == 1)
		u = u * (-1);
	return (u);
}
