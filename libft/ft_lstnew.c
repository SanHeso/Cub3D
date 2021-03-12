/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:40:32 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/12 15:43:45 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *ptr;

	if (!(ptr = (t_list*)malloc(sizeof(t_list))))
		return (0);
	ptr->content = ft_strdup(content);
	ptr->next = 0;
	return (ptr);
}
