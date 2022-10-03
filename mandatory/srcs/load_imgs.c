/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 05:47:03 by aklaikel          #+#    #+#             */
/*   Updated: 2022/10/03 21:30:33 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	load_image(t_cub *cub, char *path, t_image *img)
{
	img->image = mlx_xpm_file_to_image(cub->mlx_ptr, path, \
		&img->width, &img->height);
	if (!img->image)
	{
		ft_exit(cub);
		printf("error \nloading texture in  path : %s\n", path);
	}
	img->adr_data = (unsigned int *)mlx_get_data_addr(img->image, \
		&img->bpp, &img->sl, &img->endian);
}

void	loading(t_cub *cub)
{
	load_image(cub, cub->data.no, &cub->no);
	load_image(cub, cub->data.so, &cub->so);
	load_image(cub, cub->data.we, &cub->we);
	load_image(cub, cub->data.ea, &cub->ea);
}
