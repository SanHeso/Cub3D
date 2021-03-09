/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:26:28 by hnewman           #+#    #+#             */
/*   Updated: 2020/11/16 19:38:00 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ch_set(char n, char const *set)
{
	int t;

	t = 0;
	while (set[t])
	{
		if (set[t] == n)
			return (1);
		t++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		slen;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (0);
	slen = ft_strlen((char*)s1) - 1;
	while (s1[i] && ch_set(s1[i], set))
		i++;
	while (slen >= i && ch_set(s1[slen], set))
		slen--;
	if (!(str = (char*)malloc(slen - i + 2)))
		return (0);
	while (i < slen + 1)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
