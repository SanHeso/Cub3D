/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:43:54 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/09 20:54:52 by hnewman          ###   ########.fr       */
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

void	distribution(t_cub *all, char **arr)
{
	if (ft_strncmp(arr[0], "R", 1) && !all->pars.heightr && !arr[3])
	{
		all->pars.heightr = arr[2];
		all->pars.widthr = arr[1];
	}
	if (ft_strncmp(arr[0], "NO", 2) && !all->pars.NO && !arr[2])
		all->pars.NO = arr[1];
	if (ft_strncmp(arr[0], "SO", 2) && !all->pars.SO && !arr[2])
		all->pars.SO = arr[1];
	if (ft_strncmp(arr[0], "WE", 2) && !all->pars.WE && !arr[2])
		all->pars.WE = arr[1];
	if (ft_strncmp(arr[0], "EA", 2) && !all->pars.EA && !arr[2])
		all->pars.EA = arr[1];
	if (ft_strncmp(arr[0], "S", 1) && !all->pars.S && !arr[2])
		all->pars.S = arr[1];
	if (ft_strncmp(arr[0], "F", 1) && !all->pars.F && !arr[2])
		flo_cei();
	if (ft_strncmp(arr[0], "C", 1) && !all->pars.C && !arr[2])
		flo_cei();
}

int		parser(t_cub *all)
{
	char	*line;
	char	**arr;
	t_list	*head;

	while (get_next_line(all->pars.fd, &line))
	{
		arr = ft_split(line, ' ');

	}

	while (get_next_line(all->pars.fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	free(line);
	make_cart(&head, ft_lstsize(head));
	return (0);
}
