/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:58:28 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/24 21:01:55 by hnewman          ###   ########.fr       */
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
# include "../MLX/mlx.h"
# include "../libft/libft.h"
# define SCALE 16
# define ERR "Error! "
# define NO_DIR ERR "No such file or dirctory\n"
# define FILE ERR "Invalid file entered\n"
# define FLAG ERR "Invalid flag entered\n"
# define PARAM_MAP ERR "Invalid map parameters: "
# define NO_MAL ERR "Memory is not allocated\n"
# define RESOLUTION PARAM_MAP "Screen resolution\n"
# define NO_DISTR PARAM_MAP "Incorrect distribution\n"
# define NO_DIGIT PARAM_MAP "Not a number entered\n"
# define NO_PARAM PARAM_MAP "Parameter missing\n"
# define NO_ARG ERR "More or less arguments\n"
# define MATH ERR "Arithmetic sign introduced\n"
# define NO_COLOR ERR "Wrong color code\n"
# define NO_MAP ERR "Invalid map\n"
# define MORE_PLR ERR "Many players\n"
# define NO_PLR ERR "The player is not displayed on the map\n"
# define NO_TEX ERR "No texture found\n"
# define NO_FD ERR "File descriptor is not closed\n"
# define NO_WRITE ERR "Invalid write to file\n"
# define NO_CREATE ERR ".bmp file was not created\n"
# define MIS_MAP ERR "Missing map\n"
# define OVERFL ERR "Overflow occurred\n"

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
	int				t_wdth;
	int				t_hght;
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
	int				f[3];
	int				c[3];
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
	double			wall_x;
	double			step;
	double			tex_pstn;
	int				stp_x;
	int				stp_y;
	int				hit;
	int				side;
	int				map_x;
	int				map_y;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_x;
	int				tex_y;
	int				col;

	double			sp_x;
	double			sp_y;
	double			inv_det;
	double			tr_form_x;
	double			tr_form_y;
	int				sp_scrn_x;
	int				sp_h;
	int				sp_w;
	int				draw_start_y;
	int				draw_start_x;
	int				draw_end_y;
	int				draw_end_x;
	int				stripe;
}					t_dda;

typedef struct		s_sp
{
	float			x;
	float			y;
}					t_sp;

typedef struct		s_sort
{
	double			first;
	int				second;
}					t_sort;

typedef struct		s_cub
{
	t_win			win;
	t_win			no;
	t_win			so;
	t_win			we;
	t_win			ea;
	t_win			s;
	t_pars			pars;
	t_plr			plr;
	t_dda			dda;
	t_sp			*sp;
	char			**map;
	int				sp_count;
	int				screenshot;
}					t_cub;

int					main(int argc, char **argv);
void				init_pars(t_cub *all);
void				init_ray(t_cub *all, int x);
void				init_player(t_cub *all);
void				parser(t_cub *all);
void				valid_flo_cei(t_cub *all, char *arr, int ch);
void				valid_arg(t_cub *all, int argc, char **argv);
void				valid_screen_size(t_cub *all, char **arr);
void				valid_cart(t_cub *all, int y, int x, int size);
void				valid_texture(t_win *tex, char **mas, char **root);
void				validate(t_cub *all, int size);
void				real_screen_size(t_cub *all);
void				memfree(char ***arr);
void				end_of_prog(char *s);
int					key_press(int keycode, t_cub *all);
int					key_release(int keycode, t_cub *all);
int					close_prog(int keycode);
int					mod_atoi(char *str);
int					ch_arg(char **arr);
int					key_release(int keycode, t_cub *all);
int					key_press(int keycode, t_cub *all);
void				move_ws(t_cub *all);
void				move_ad(t_cub *all);
void				rotation(t_cub *all);
void				step(t_cub *all);
void				alg_dda(t_dda *dda, char **map);
void				fish_eye(t_dda *dda, t_plr *plr);
void				height_wall(t_dda *dda, t_pars *pars);
void				draw_wall(t_cub *all, int x, int y);
void				ceil_floor(t_cub *all, int x);
void				drctn_plr(t_cub *all, int ch);
int					transit(char *line, t_cub *all);
void				wall_hit(t_cub *all);
void				texture(t_cub *all);
void				texture_size(t_cub *all, int width, int height);
void				sp_sum(t_cub *all);
void				order_sort(t_sort *order, int qua);
void				pos_sp_plr(t_cub *all, int i, int j);
int					ft_mlx_pixel_get(t_win *data, int x, int y);
void				ft_mlx_pixel_put(t_win *data, int x, int y, int col);
int					rgb(int arr[3]);
void				sp_sort(double *dist, int *order, int qua);
void				sp_distant(t_cub *all, double *sp_dist, int *sp_ord);
void				sp_pos(t_cub *all, int *sp_ord, int i);
void				sp_height_width(t_cub *all);
void				sp_draw(t_cub *all, double *zbuf);
void				sprite(t_cub *all, double *zbuf, int *sp_order, int x);
void				screenshot(t_cub *all, const char *name);
int					check_comma(char *arr);

#endif
