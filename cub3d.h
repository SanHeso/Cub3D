/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:58:28 by hnewman           #+#    #+#             */
/*   Updated: 2021/02/13 19:02:04 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "minilibx_opengl_20191021/mlx.h"
# include "libft/libft.h"

typedef struct		s_pix
{
	void			*img;
	char			*adrs;
	int				bits;
	int				len;
	int				end;
}					t_pix;

typedef struct		s_win
{
	void	*mlx;
	void	*img;
	void	*win;
	void	*adrs;
	int		line;
	int		end;
	int		bpp;
}					t_win;

typedef struct		s_ptr
{
	int		x;
	int		y;
}					t_ptr;

typedef struct		s_plr
{
	float	x;
	float	y;
	float	dir;
	float	start;
	float	end;
}					t_plr;

typedef struct		s_pars
{
	void			*cont;
	struct s_pars	*next;
}					t_pars;

#endif
