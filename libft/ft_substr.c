/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:57:52 by hnewman           #+#    #+#             */
/*   Updated: 2021/02/11 18:34:05 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	min(size_t x, size_t y)
{
	if (x < y)
		return (x);
	return (y);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	if (!s)
		return (0);
	len = min((unsigned int)ft_strlen((char*)s) - start, len);
	if (!(str = (char*)ft_calloc((len + 1), sizeof(char))))
		return (0);
	if (start >= (unsigned int)ft_strlen((char*)s))
		return (str);
	while (len--)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
