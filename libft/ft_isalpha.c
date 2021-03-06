/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:37:01 by hnewman           #+#    #+#             */
/*   Updated: 2020/11/24 15:44:33 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int ch)
{
	if (ch >= 65 && ch <= 90)
		return (1);
	else if (ch >= 97 && ch <= 122)
		return (1);
	return (0);
}
