/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 05:47:03 by aklaikel          #+#    #+#             */
/*   Updated: 2022/09/29 23:46:32 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	load_image(t_cub *cub, char *path, t_image *img)
{
	img->image = mlx_xpm_file_to_image(cub->mlx_ptr, path, \
		&img->width, &img->height);
	if (!img->image)
	{
		_free_(cub);
		printf("error \nloading texture in  path : %s\n", path);
		exit(0);
	}
	img->adr_data = (unsigned int *)mlx_get_data_addr(img->image, \
		&img->bpp, &img->sl, &img->endian);
}

static void	continue_loading(t_cub *cub)
{
	load_image(cub, "./texture/07.xpm", &cub->man[8]);
	load_image(cub, "./texture/08.xpm", &cub->man[9]);
	load_image(cub, "./texture/09.xpm", &cub->man[10]);
	load_image(cub, "./texture/10.xpm", &cub->man[11]);
	load_image(cub, "./texture/11.xpm", &cub->man[12]);
	load_image(cub, "./texture/12.xpm", &cub->man[13]);
	load_image(cub, "./texture/13.xpm", &cub->man[14]);
	load_image(cub, "./texture/14.xpm", &cub->man[15]);
	load_image(cub, "./texture/15.xpm", &cub->man[16]);
	load_image(cub, "./texture/16.xpm", &cub->man[17]);
	load_image(cub, "./texture/17.xpm", &cub->man[18]);
	load_image(cub, "./texture/18.xpm", &cub->man[19]);
	load_image(cub, "./texture/19.xpm", &cub->man[20]);
	load_image(cub, "./texture/20.xpm", &cub->man[21]);
	load_image(cub, "./texture/21.xpm", &cub->man[22]);
	load_image(cub, "./texture/22.xpm", &cub->man[23]);
	load_image(cub, "./texture/23.xpm", &cub->man[24]);
	load_image(cub, "./texture/24.xpm", &cub->man[25]);
	load_image(cub, "./texture/25.xpm", &cub->man[26]);
	load_image(cub, "./texture/26.xpm", &cub->man[27]);
	load_image(cub, "./texture/27.xpm", &cub->man[28]);
}

void	loading(t_cub *cub)
{
	load_image(cub, cub->data.no, &cub->no);
	load_image(cub, cub->data.so, &cub->so);
	load_image(cub, cub->data.we, &cub->we);
	load_image(cub, cub->data.ea, &cub->ea);
	load_image(cub, "./texture/door.xpm", &cub->door);
	load_image(cub, "./texture/butterfly1.xpm", &cub->butterfly[0]);
	load_image(cub, "./texture/butterfly2.xpm", &cub->butterfly[1]);
	load_image(cub, "./texture/butterfly3.xpm", &cub->butterfly[2]);
	load_image(cub, "./texture/butterfly4.xpm", &cub->butterfly[3]);
	load_image(cub, "./texture/00.xpm", &cub->man[0]);
	load_image(cub, "./texture/01.xpm", &cub->man[1]);
	load_image(cub, "./texture/02.xpm", &cub->man[2]);
	load_image(cub, "./texture/28.xpm", &cub->man[3]);
	load_image(cub, "./texture/03.xpm", &cub->man[4]);
	load_image(cub, "./texture/04.xpm", &cub->man[5]);
	load_image(cub, "./texture/05.xpm", &cub->man[6]);
	load_image(cub, "./texture/06.xpm", &cub->man[7]);
	continue_loading(cub);
}
