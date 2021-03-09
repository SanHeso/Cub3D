/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 16:24:35 by hnewman           #+#    #+#             */
/*   Updated: 2020/11/20 14:50:37 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	*u;

	i = 0;
	t = (unsigned char*)s1;
	u = (unsigned char*)s2;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (t[i] - u[i]);
		if (!s1 || !s2)
			return (t[i] - u[i]);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (t[i] - u[i]);
		i++;
	}
	return (0);
}
