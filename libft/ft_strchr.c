/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:52:02 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/22 19:26:16 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int ch)
{
	int	i;

	i = 0;
	if (!ch)
		return (0);
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)ch)
			return (str + i);
		i++;
	}
	if ((unsigned char)str[i] == (unsigned char)ch)
		return (str + i);
	return (0);
}
