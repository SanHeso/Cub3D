/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:43:54 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/22 17:48:01 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_cart(t_list **head, t_cub *all, int size)
{
	t_list	*tmp = *head;
	int		i;

	if (!(all->map = ft_calloc(size + 1, sizeof(char *))))
		end_of_prog();
	i = 0;
	while (tmp)
	{
		all->map[i++] = tmp->content;
		tmp = tmp->next;
	}
	i = 0;
	while (all->map[i++])
	{
		ft_putendl_fd(all->map[i], 1);
		free(all->map[i]);
	}
}

void	distribution(t_cub *all, char **arr)
{
	if (!ft_strncmp(arr[0], "R", 1) && !all->pars.h && !arr[3])
	{
		all->pars.h = ft_atoi(arr[2]);
		all->pars.w = ft_atoi(arr[1]);
	}
	else if (!ft_strncmp(arr[0], "NO", 2) && !all->pars.no && ch_arg(int *arr))
		all->pars.no = ft_strdup(arr[1]);
	else if (!ft_strncmp(arr[0], "SO", 2) && !all->pars.so && ch_arg(int *arr))
		all->pars.so = ft_strdup(arr[1]);
	else if (!ft_strncmp(arr[0], "WE", 2) && !all->pars.we && ch_arg(int *arr))
		all->pars.we = ft_strdup(arr[1]);
	else if (!ft_strncmp(arr[0], "EA", 2) && !all->pars.ea && ch_arg(int *arr))
		all->pars.ea = ft_strdup(arr[1]);
	else if (!ft_strncmp(arr[0], "S", 1) && !all->pars.s && ch_arg(int *arr))
		all->pars.s = ft_strdup(arr[1]);
	else if (!ft_strncmp(arr[0], "F", 1) && !all->pars.f && ch_arg(int *arr))
		valid_flo_cei(all, arr[1], 'F');
	else if (!ft_strncmp(arr[0], "C", 1) && !all->pars.c && ch_arg(int *arr))
		valid_flo_cei(all, arr[1], 'C');
	else
		end_of_prog();
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
	}
	free(line);

	while (get_next_line(all->pars.fd, &line))
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		free(line);
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	free(line);
	make_cart(&head, all, ft_lstsize(head));
	free(head);
}
