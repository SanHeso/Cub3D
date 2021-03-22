/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:58:28 by hnewman           #+#    #+#             */
/*   Updated: 2021/03/22 19:20:31 by hnewman          ###   ########.fr       */
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
# define SCALE				16
# define BMP_EXTN			".bmp"
# define BMP_IDENTIFIER		"BM"
# define BMP_BYTEPERPIXEL	4
# define BMP_SIZEOFHEADER	54
# define BMP_SIZEOFINFO		40
# define BMP_RESERVED		0
# define BMP_PLANES			1
# define BMP_BITPERPIXEL	32
# define BMP_COMPRESSION	0
# define BMP_SIZEIMAGE		0
# define BMP_XPELSPERMETER	0
# define BMP_YPELSPERMETER	0
# define BMP_CLRUSED		0
# define BMP_CLRIMPORTANT	0

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
	t_bitmapfileheader	fileheader;
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
	t_pix			pix;
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
void				valid_flo_cei(t_cub *all, char *arr);
void				valid_arg(t_cub *all, int argc, char **argv);
void				memfree(char ***arr);
void				end_of_prog(void);
int					key_press(int keycode, t_cub *all);
int					key_release(int keycode, t_cub *all);
int					close_prog(int keycode, t_cub *all);
int					mod_atoi(char *str);
int					ch_arg(int *arr);
void				move_ws(t_cub *all);
void				move_ad(t_cub *all);
void				rotation(t_cub *all);

#endif
