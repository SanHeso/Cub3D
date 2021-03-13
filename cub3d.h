/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:58:28 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/13 18:42:33 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft/libft.h"
# define SCALE 16

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
	void			*mlx;
	void			*img;
	void			*win;
	void			*adrs;
	int				line;
	int				end;
	int				bpp;
}					t_win;

typedef struct		s_pars
{
	int				fd;
	int				heir;
	int				widr;
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	char			*S;
	float			F[3];
	float			C[3];
}					t_pars;

typedef struct		s_plr
{
	float			x;
	float			y;
	float			dir;
	float			start;
	float			end;
}					t_plr;

typedef struct		s_cub
{
	t_pix			pix;
	t_win			win;
	t_pars			pars;
	t_plr			plr;
	char			**map;
}					t_cub;

void				newcub(t_cub *all);
void				parser(t_cub *all);
void				flocei(t_cub *all, char *arr, int ch);
void				memfree(char ***arr);
void				end_of_prog(void);

#endif
