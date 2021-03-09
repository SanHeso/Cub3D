/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:18:19 by hnewman           #+#    #+#             */
/*   Updated: 2020/11/28 13:43:09 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t a;
	size_t dlen;
	size_t slen;

	a = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dlen >= dstsize)
		return (dstsize + slen);
	while (src[a] && a < dstsize - dlen - 1)
	{
		dst[a + dlen] = src[a];
		a++;
	}
	dst[a + dlen] = '\0';
	return (dlen + slen);
}
