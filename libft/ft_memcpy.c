/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:53:59 by hnewman           #+#    #+#             */
/*   Updated: 2020/11/11 17:02:49 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;
	char	*t;
	char	*u;

	i = 0;
	t = (char*)dest;
	u = (char*)src;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		t[i] = u[i];
		i++;
	}
	return (t);
}
