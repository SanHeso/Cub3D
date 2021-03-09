/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:43:54 by hnewman           #+#    #+#             */
/*   Updated: 2021/02/14 15:56:55 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_cart(t_list **head, int size)
{
	t_list	*tmp = *head;
	char	**cart;
	int		i;

	if (!(cart = ft_calloc(size + 1, sizeof(char *))))
		perror("Произошла ошибка: ");
	i = 0;
	while (tmp)
	{
		cart[i++] = tmp->content;
		tmp = tmp->next;
	}
	i = 0;
	while (cart[i++])
		ft_putendl_fd(cart[i], 1);
	free(cart);
}

int		main(void)
{
	int		fd = open("cart.txt", O_RDONLY);
	char	*line;
	t_list	*head;

	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	free(line);
	make_cart(&head, ft_lstsize(head));
	return (0);
}
