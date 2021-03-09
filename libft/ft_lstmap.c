/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:30:12 by hnewman           #+#    #+#             */
/*   Updated: 2021/02/09 14:47:38 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *tmp;

	if (!lst || !f || !del)
		return (NULL);
	tmp = NULL;
	while (lst)
	{
		new = ft_lstnew(lst->content);
		if (!new)
		{
			del(tmp);
			return (NULL);
		}
		new->content = f(new->content);
		ft_lstadd_back(&tmp, new);
		lst = lst->next;
	}
	ft_lstadd_back(&tmp, NULL);
	return (tmp);
}
