/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:21:08 by hnewman           #+#    #+#             */
/*   Updated: 2020/11/18 19:21:22 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int m)
{
	int i;

	i = 0;
	if (m == 0)
		return (1);
	if (m < 0)
		i++;
	while (m != 0)
	{
		m = m / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 1;
	if (n < 0)
	{
		j = 1;
		k = -1;
	}
	i = len(n);
	if (!(str = malloc(i + 1)))
		return (0);
	str[i] = '\0';
	while (--i >= j)
	{
		str[i] = (n % 10) * k + '0';
		n = n / 10;
	}
	if (j == 1)
		str[i] = '-';
	return (str);
}
