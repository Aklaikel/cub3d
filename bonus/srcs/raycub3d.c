 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:54:38 by anass             #+#    #+#             */
/*   Updated: 2022/09/29 17:53:36 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	souris(int x, int y, t_cub *cub)
{
	if (x >= SCREENW || x <= 0 || y >= SCREENH || y <= 0)
		return (0);
	if (x < cub->souris)
	{
		rotate_vec(&(cub->plan), &(cub->plan), -0.06);
		rotate_vec(&(cub->direction), &(cub->direction), -0.06);
	}
	else if (cub->souris < x)
	{
		rotate_vec(&(cub->plan), &(cub->plan), 0.06);
		rotate_vec(&(cub->direction), &(cub->direction), 0.06);
	}
	cub->souris = x;
	return (0);
}

void	init(t_cub *cub, t_data data)
{
	cub->mlx_ptr = mlx_init();
	cub->mlx_window = mlx_new_window(cub->mlx_ptr, SCREENW, SCREENH, "Cub3D");
	cub->data = data;
	cub->postion.x = cub->data.x + .0001;
	cub->postion.y = cub->data.y + .0001;
	cub->data.map[cub->data.y][cub->data.x] = '0';
	cub->direction.x = 0;
	if (cub->data.direction == 'W')
		cub->direction.x = -1;
	else if (cub->data.direction == 'E')
		cub->direction.x = 1;
	cub->direction.y = 0;
	if (cub->data.direction == 'N')
		cub->direction.y = -1;
	else if (cub->data.direction == 'S')
		cub->direction.y = 1;
	cub->tv.image = mlx_new_image(cub->mlx_ptr, SCREENW, SCREENH);
	cub->minimap.image = mlx_new_image(cub->mlx_ptr, MINIMAPW, MINIMAPH);
	cub->minimap.adr_data = (unsigned int *)mlx_get_data_addr(\
		cub->minimap.image, &cub->minimap.bpp, &cub->minimap.sl, \
			&cub->minimap.endian);
	cub->tv.adr_data = (unsigned int *)mlx_get_data_addr(cub->tv.image, \
		&cub->tv.bpp, &cub->tv.sl, &cub->tv.endian);
}

void	raycastcub3d(t_data data)
{
	t_cub	*cub;

	cub = NULL;
	cub = malloc(sizeof(t_cub));
	if (!cub)
		exit(1);
	init(cub, data);
	colors(cub);
	loading(cub);
	rotate_vec(&(cub->plan), &(cub->direction), M_PI / 2);
	multiple_vec_nbr(&(cub->plan), tan(M_PI / 6));
	mlx_loop_hook(cub->mlx_ptr, &game, cub);
	mlx_hook(cub->mlx_window, 3, 2, key_release, cub);
	mlx_hook(cub->mlx_window, 2, 1, key_press, cub);
	mlx_hook(cub->mlx_window, 17, 1L, ft_exit, cub);
	mlx_hook(cub->mlx_window, 6, 1L, souris, cub);
	mlx_loop(cub->mlx_ptr);
}
