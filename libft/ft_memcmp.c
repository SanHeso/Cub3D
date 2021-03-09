/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:10:09 by hnewman           #+#    #+#             */
/*   Updated: 2020/11/12 14:41:09 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void *s1, void *s2, size_t n)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	*u;

	i = 0;
	t = (unsigned char*)s1;
	u = (unsigned char*)s2;
	while (i < n)
	{
		if (t[i] != u[i])
			return (t[i] - u[i]);
		i++;
	}
	return (0);
}
