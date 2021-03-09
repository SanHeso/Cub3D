/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 20:12:39 by hnewman           #+#    #+#             */
/*   Updated: 2021/02/14 15:40:32 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*check_rem(char *rem, char **line)
{
	char	*find;

	find = NULL;
	if (rem)
	{
		if ((find = ft_strchr(rem, '\n')))
		{
			*find = '\0';
			*line = ft_strdup(rem);
			ft_strlcpy(rem, ++find, BUFFER_SIZE);
		}
		else
			*line = ft_strdup(rem);
	}
	else
		*line = ft_strdup("");
	return (find);
}

char		*free_rem(char *rem)
{
	char	*tmp;

	tmp = rem;
	rem = NULL;
	free(tmp);
	return (rem);
}

char		*ft_strjoin_ch(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	x;
	char	*str;

	i = 0;
	j = 0;
	x = ft_strlen(s1);
	if (!s1)
		return ((char*)s2);
	if (!(str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (i < x)
		str[j++] = s1[i++];
	i = 0;
	x = ft_strlen(s2);
	while (i < x)
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*rem;
	int			get;
	char		*find;

	if ((read(fd, 0, 0)) < 0 || !line || BUFFER_SIZE <= 0
	|| !(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	find = check_rem(rem, line);
	while (!find && (get = read(fd, buf, BUFFER_SIZE)))
	{
		buf[get] = '\0';
		if ((find = ft_strchr(buf, '\n')))
		{
			*find = '\0';
			rem = free_rem(rem);
			rem = ft_strdup(++find);
		}
		*line = ft_strjoin_ch(*line, buf);
	}
	free(buf);
	if (find)
		return (1);
	rem = free_rem(rem);
	return (0);
}
