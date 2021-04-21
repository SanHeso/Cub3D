/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:23:06 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/21 14:34:11 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		set_bmp_data_from_image(t_bmpfile *bmp, t_cub *all)
{
	ft_memcpy(bmp->filehead.type, "BM", 2);
	bmp->filehead.size = all->pars.w * all->pars.h * 4 + 54;
	bmp->filehead.reserved = 0;
	bmp->filehead.offset = 54;
	bmp->info.size = 40;
	bmp->info.width = all->pars.w;
	bmp->info.height = -all->pars.h;
	bmp->info.planes = 1;
	bmp->info.bitcount = 32;
	bmp->info.compression = 0;
	bmp->info.sizeimage = 0;
	bmp->info.xpelspermeter = 0;
	bmp->info.ypelspermeter = 0;
	bmp->info.clrused = 0;
	bmp->info.clrimportant = 0;
	bmp->data = all->win.adrs;
}

static int		write_bitmapinfo(int fd, t_bitmapinfo *info)
{
	if (write(fd, &info->size, sizeof(info->size)) < 0)
		return (0);
	if (write(fd, &info->width, sizeof(info->width)) < 0)
		return (0);
	if (write(fd, &info->height, sizeof(info->height)) < 0)
		return (0);
	if (write(fd, &info->planes, sizeof(info->planes)) < 0)
		return (0);
	if (write(fd, &info->bitcount, sizeof(info->bitcount)) < 0)
		return (0);
	if (write(fd, &info->compression, sizeof(info->compression)) < 0)
		return (0);
	if (write(fd, &info->sizeimage, sizeof(info->sizeimage)) < 0)
		return (0);
	if (write(fd, &info->xpelspermeter, sizeof(info->xpelspermeter)) < 0)
		return (0);
	if (write(fd, &info->ypelspermeter, sizeof(info->ypelspermeter)) < 0)
		return (0);
	if (write(fd, &info->clrused, sizeof(info->clrused)) < 0)
		return (0);
	if (write(fd, &info->clrimportant, sizeof(info->clrimportant)) < 0)
		return (0);
	return (1);
}

static int		write_bitmapfileheader(int fd, t_bitmapfileheader *hdr)
{
	if (write(fd, &hdr->type, sizeof(hdr->type)) < 0)
		return (0);
	if (write(fd, &hdr->size, sizeof(hdr->size)) < 0)
		return (0);
	if (write(fd, &hdr->reserved, sizeof(hdr->reserved)) < 0)
		return (0);
	if (write(fd, &hdr->offset, sizeof(hdr->offset)) < 0)
		return (0);
	return (1);
}

int				ft_write_bmp(int fd, t_bmpfile *bitmap)
{
	if (fd > 0)
	{
		if (!(write_bitmapfileheader(fd, &bitmap->filehead)))
			return (0);
		if (!(write_bitmapinfo(fd, &bitmap->info)))
			return (0);
		if (write(fd, bitmap->data,
			bitmap->filehead.size - bitmap->filehead.offset) < 0)
			return (0);
		return (1);
	}
	return (0);
}

void			screenshot(t_cub *all, const char *name)
{
	int			fd;
	char		*file;
	t_bmpfile	bmp_data;

	file = ft_strjoin(name, ".bmp");
	if ((fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR)) < 0)
		end_of_prog(NO_CREATE);
	set_bmp_data_from_image(&bmp_data, all);
	if (!(ft_write_bmp(fd, &bmp_data)))
	{
		if (close(fd) < 0)
			end_of_prog(NO_FD);
		end_of_prog(NO_WRITE);
	}
	if (close(fd) < 0)
		end_of_prog(NO_FD);
	exit(1);
}
