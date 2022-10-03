/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamd <ael-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:05:45 by aklaikel          #+#    #+#             */
/*   Updated: 2022/10/03 19:16:39 by ael-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>

static void	render_butterfly(t_cub *cub)
{
	static int	i;

	mlx_put_image_to_window(cub->mlx_ptr, cub->mlx_window, \
		cub->butterfly[i / 10].image, \
		SCREENW / 4, SCREENH - cub->butterfly[i / 10].height);
	i = (i + 1) % 40;
}

static void	rays(t_cub *cub)
{
	cub->raydirection.x = cub->direction.x + cub->plan.x * cub->camera.x;
	cub->raydirection.y = cub->direction.y + cub->plan.y * cub-> camera.x;
	cub->map.x = (int)cub->postion.x;
	cub->map.y = (int)cub->postion.y;
	cub->nextside.x = fabs(1 / cub->raydirection.x);
	cub->nextside.y = fabs(1 / cub->raydirection.y);
	cub->whatdirection.x = 1;
	cub->whatdirection.y = 1;
	if (cub->raydirection.x < 0)
	{
		cub->whatdirection.x = -1;
		cub->whichwall.x = (cub->postion.x - cub->map.x) * cub->nextside.x;
	}
	else
		cub->whichwall.x = (cub->map.x + 1 - cub->postion.x) * cub->nextside.x;
	if (cub->raydirection.y < 0)
	{
		cub->whatdirection.y = -1;
		cub->whichwall.y = (cub->postion.y - cub->map.y) * cub->nextside.y;
	}
	else
		cub->whichwall.y = (cub->map.y - cub->postion.y + 1) * cub->nextside.y;
}

int	game(t_cub *cub)
{
	int	x;

	x = -1;
	while (++x < SCREENW)
	{
		cub->camera.x = 2.0 * x / (SCREENW - 1) - 1;
		rays(cub);
		dda_algorithm(cub);
		cub->walldistance = cub->whichwall.x - cub->nextside.x;
		if (cub->whichside)
			cub->walldistance = cub->whichwall.y - cub->nextside.y;
		drawtoscreen(cub, x);
	}
	minimap(cub);
	key_listner(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->mlx_window, cub->tv.image, 0, 0);
	mlx_put_image_to_window(cub->mlx_ptr, cub->mlx_window, \
		cub->minimap.image, 0, 0);
	render_butterfly(cub);
	return (0);
}
