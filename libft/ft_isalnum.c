/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:00:42 by hnewman           #+#    #+#             */
/*   Updated: 2020/11/09 18:06:42 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int ch)
{
	if (ch >= 48 && ch <= 57)
		return (1);
	else if (ch >= 65 && ch <= 90)
		return (1);
	else if (ch >= 97 && ch <= 122)
		return (1);
	return (0);
}
