/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:17:54 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/25 16:24:55 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	if (lst[0] == NULL)
		return ;
	tmp = lst[0];
	while (tmp)
	{
		lst[0] = lst[0]->next;
		if (tmp->content)
			del(tmp->content);
		del(tmp);
		tmp = lst[0];
	}
}
