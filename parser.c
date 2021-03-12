/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:43:54 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/12 19:42:24 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_cart(t_list **head, t_cub *all, int size)
{
	t_list	*tmp = *head;
	int		i;

	if (!(all->cart = ft_calloc(size + 1, sizeof(char *))))
		end_of_prog();
	i = 0;
	while (tmp)
	{
		all->cart[i++] = tmp->content;
		tmp = tmp->next;
	}
	i = 0;
	while (all->cart[i++])
	{
		ft_putendl_fd(all->cart[i], 1);
		free(all->cart[i]);
	}
}

void	distribution(t_cub *all, char **arr)
{
	if (!ft_strncmp(arr[0], "R", 1) && !all->pars.heightr && !arr[3])
	{
		all->pars.heightr = ft_atoi(arr[2]);
		all->pars.widthr = ft_atoi(arr[1]);
	}
	if (!ft_strncmp(arr[0], "NO", 2) && !all->pars.NO && !arr[2])
		all->pars.NO = ft_strdup(arr[1]);
	if (!ft_strncmp(arr[0], "SO", 2) && !all->pars.SO && !arr[2])
		all->pars.SO = ft_strdup(arr[1]);
	if (!ft_strncmp(arr[0], "WE", 2) && !all->pars.WE && !arr[2])
		all->pars.WE = ft_strdup(arr[1]);
	if (!ft_strncmp(arr[0], "EA", 2) && !all->pars.EA && !arr[2])
		all->pars.EA = ft_strdup(arr[1]);
	if (!ft_strncmp(arr[0], "S", 1) && !all->pars.S && !arr[2])
		all->pars.S = ft_strdup(arr[1]);
	if (!ft_strncmp(arr[0], "F", 1) && !arr[2])
		flocei(all, arr[1], 'F');
	if (!ft_strncmp(arr[0], "C", 1) && !arr[2])
		flocei(all, arr[1], 'C');
}

void	parser(t_cub *all)
{
	char	*line;
	char	**arr;
	t_list	*head;

	while (get_next_line(all->pars.fd, &line) && line[0] != '\0')
	{
		arr = ft_split(line, ' ');
		distribution(all, arr);
		memfree(&arr);
		printf("%p ", line);
		printf("%s\n", line);
		free(line);
	}
	free(line);

	printf("\n%d ", all->pars.widthr);
	printf("%d\n", all->pars.heightr);
	printf("%s\n", all->pars.NO);
	printf("%s\n", all->pars.SO);
	printf("%s\n", all->pars.WE);
	printf("%s\n", all->pars.EA);
	printf("%s\n", all->pars.S);
	printf("%f %f %f\n", all->pars.F[0], all->pars.F[1], all->pars.F[2]);
	printf("%f %f %f\n", all->pars.C[0], all->pars.C[1], all->pars.C[2]);

	while (get_next_line(all->pars.fd, &line))
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		free(line);
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	free(line);
	make_cart(&head, all, ft_lstsize(head));
}
