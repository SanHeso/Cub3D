/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:28:55 by hnewman           #+#    #+#             */
/*   Updated: 2020/11/09 18:13:05 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t i;
	size_t a;

	i = 0;
	a = 0;
	if (to_find[a] == '\0')
		return (&str[i]);
	while (str[i] != '\0' && i < len)
	{
		while (str[i + a] == to_find[a] && to_find[a] && i + a < len)
			a++;
		if (!to_find[a])
			return (&str[i]);
		i++;
		a = 0;
	}
	return (0);
}
