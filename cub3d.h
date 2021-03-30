/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:58:28 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/30 17:01:52 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>
# include "minilibx_opengl_20191021/mlx.h"
# include "libft/libft.h"
# define SCALE		16

typedef struct		s_bitmapfileheader
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
}					t_bitmapfileheader;

typedef struct		s_bitmapinfo
{
	int				size;
	int				width;
	int				height;
	short			planes;
	short			bitcount;
	int				compression;
	int				sizeimage;
	int				xpelspermeter;
	int				ypelspermeter;
	int				clrused;
	int				clrimportant;
}					t_bitmapinfo;

typedef struct		s_bmpfile
{
	t_bitmapfileheader	filehead;
	t_bitmapinfo		info;
	char				*data;
}					t_bmpfile;

typedef struct		s_win
{
	void			*mlx;
	void			*img;
	void			*win;
	void			*adrs;
	int				len;
	int				end;
	int				bpp;
	int				w;
	int				h;
	int				cntr_x;
}					t_win;

typedef struct		s_pars
{
	int				fd;
	int				h;
	int				w;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	float			f[3];
	float			c[3];
}					t_pars;

typedef struct		s_plr
{
	double			pstn_x;
	double			pstn_y;
	double			drctn_x;
	double			drctn_y;
	double			pln_x;
	double			pln_y;
	double			spd;
	double			rttn_spd;
	int				bttn_w;
	int				bttn_a;
	int				bttn_s;
	int				bttn_d;
	int				rttn;
}					t_plr;

typedef struct		s_dda
{
	double			cmr_x;
	double			r_dr_x;
	double			r_dr_y;
	double			sd_dst_x;
	double			sd_dst_y;
	double			dlt_dst_x;
	double			dlt_dst_y;
	double			prp_wll_dst;
	int				stp_x;
	int				stp_y;
	int				hit;
	int				side;
	int				map_x;
	int				map_y;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_dda;

typedef struct		s_cub
{
	t_win			win;
	t_pars			pars;
	t_plr			plr;
	t_dda			dda;

	char			**map;
	int				scrn_sht;
}					t_cub;

void				init_pars(t_cub *all);
void				init_ray(t_cub *all, int x);
void				init_player(t_cub *all);
void				parser(t_cub *all);
void				valid_flo_cei(t_cub *all, char *arr, int ch);
void				valid_arg(t_cub *all, int argc, char **argv);
void				valid_screen_size(t_cub *all, char **arr);
void				valid_cart(t_cub *all, int x, int y);
void				real_screen_size(t_cub *all);
void				memfree(char ***arr);
void				end_of_prog(void);
int					key_press(int keycode, t_cub *all);
int					key_release(int keycode, t_cub *all);
int					close_prog(int keycode);
int					mod_atoi(char *str);
int					ch_arg(char *arr);
int					key_release(int keycode, t_cub *all);
int					key_press(int keycode, t_cub *all);
void				move_ws(t_cub *all);
void				move_ad(t_cub *all);
void				rotation(t_cub *all);
void				step(t_cub *all);
void				dda(t_dda *dda, char **map);
void				fish_eye(t_dda *dda, t_plr *plr);
void				height_wall(t_dda *dda, t_pars *pars);
void				wall(t_cub *all, int x);
void				ceil_floor(t_cub *all, int x);

#endif
