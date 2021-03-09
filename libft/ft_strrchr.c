/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:12:36 by hnewman           #+#    #+#             */
/*   Updated: 2020/11/28 13:24:45 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int ch)
{
	int count;

	count = ft_strlen((char *)str);
	while (count >= 0)
	{
		if (str[count] == ch)
			return (((char *)str + count));
		count--;
	}
	return (0);
}
