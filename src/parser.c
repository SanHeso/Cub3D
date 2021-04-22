/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:43:54 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/22 16:51:53 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	make_cart(t_list **head, t_cub *all, int size)
{
	t_list	*tmp = *head;
	int		i;

	if (!(all->map = ft_calloc(size + 1, sizeof(char *))))
		end_of_prog(NO_MAL);
	i = 0;
	while (tmp)
	{
		all->map[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	i = 0;
	validate(all);
	ft_lstclear(head, free);
}

void	distribution(t_cub *all, char **arr)
{
	if (!ft_strncmp(arr[0], "R", 2) && !all->pars.h && !arr[3])
		valid_screen_size(all, arr);
	else if (!ft_strncmp(arr[0], "NO", 3) && !all->pars.no && ch_arg(arr))
		valid_texture(&all->no, arr, &all->pars.no);
	else if (!ft_strncmp(arr[0], "SO", 3) && !all->pars.so && ch_arg(arr))
		valid_texture(&all->so, arr, &all->pars.so);
	else if (!ft_strncmp(arr[0], "WE", 3) && !all->pars.we && ch_arg(arr))
		valid_texture(&all->we, arr, &all->pars.we);
	else if (!ft_strncmp(arr[0], "EA", 3) && !all->pars.ea && ch_arg(arr))
		valid_texture(&all->ea, arr, &all->pars.ea);
	else if (!ft_strncmp(arr[0], "S", 2) && !all->pars.s && ch_arg(arr))
		valid_texture(&all->s, arr, &all->pars.s);
	else if (!ft_strncmp(arr[0], "F", 2) && all->pars.f[0] == -1 && ch_arg(arr))
		valid_flo_cei(all, arr[1], 'F');
	else if (!ft_strncmp(arr[0], "C", 2) && all->pars.c[0] == -1 && ch_arg(arr))
		valid_flo_cei(all, arr[1], 'C');
	else
		end_of_prog(NO_DISTR);
}

void	parser(t_cub *all)
{
	char	*line;
	char	**arr;
	t_list	*head;

	while ((get_next_line(all->pars.fd, &line)) != -1 && !transit(line, all))
	{
		if (line[0] != '\0')
		{
			arr = ft_split(line, ' ');
			distribution(all, arr);
			memfree(&arr);
		}
	}
	ft_lstadd_back(&head, ft_lstnew(line));
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
