/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 05:36:26 by aklaikel          #+#    #+#             */
/*   Updated: 2022/09/29 01:14:35 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	maxx(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	add_pixel(t_cub *cub, int x, int y, unsigned int color)
{
	int	i;
	int	j;
	int	vx;
	int	vy;
	int	scale;

	scale = MINIMAPW / maxx(cub->data.width, cub->data.height);
	j = 0;
	while (j < scale)
	{
		i = 0;
		while (i < scale)
		{
			vx = x * scale + j;
			vy = y * scale + i;
			cub->minimap.adr_data[(vx * MINIMAPW) + vy] = color;
			i++;
		}
		j++;
	}
}

static void	put_nothing(t_cub *cub)
{
	int		i;
	int		j;
	t_color	n;

	n.argb.a = 255;
	n.argb.r = 0;
	n.argb.g = 0;
	n.argb.b = 0;
	i = 0;
	while (i < MINIMAPH)
	{
		j = 0;
		while (j < MINIMAPW)
		{
			cub->minimap.adr_data[(i * MINIMAPW) + j] = n.color;
			j++;
		}
		i++;
	}
}

static unsigned int	choosecolor(int x)
{
	unsigned int	s;

	if (x == 1)
		s = 0x0000FF;
	if (x == 2)
		s = 0xFF0000;
	if (x == 3)
		s = 0x00FF00;
	return (s);
}

void	minimap(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	put_nothing(cub);
	while (cub->data.map[i] && i < cub->data.height)
	{
		j = 0;
		while (cub->data.map[i][j] && j < cub->data.width)
		{
			if ((int)cub->postion.x == j && (int)cub->postion.y == i)
				add_pixel(cub, i, j, choosecolor(2));
			else if (cub->data.map[i][j] == '1')
				add_pixel(cub, i, j, choosecolor(1));
			else if (cub->data.map[i][j] == 'D')
				add_pixel(cub, i, j, choosecolor(3));
			j++;
		}
		i++;
	}
}
