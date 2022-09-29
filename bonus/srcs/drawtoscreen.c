/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawtoscreen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 05:57:01 by aklaikel          #+#    #+#             */
/*   Updated: 2022/09/29 17:45:09 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	which_texture(t_cub *cub)
{
	if (cub->whichside == 0 && cub->raydirection.x > 0)
		cub->draw = &cub->ea;
	else if (cub->whichside == 0)
		cub->draw = &cub->we;
	if (cub->whichside == 1 && cub->raydirection.y > 0)
		cub->draw = &cub->so;
	else if (cub->whichside == 1)
		cub->draw = &cub->no;
	if (cub->doorhit)
		cub->draw = &cub->door;
	cub->text.x = (int)(cub->wallx * (double)cub->draw->width);
	if ((cub->whichside == 0 && cub->raydirection.x > 0)
		|| (cub->whichside == 1 && cub->raydirection.y < 0))
		cub->text.x = cub->draw->width - cub->text.x - 1;
}

static void	draw_texture(t_cub *cub, int draw_s, int draw_e, int x)
{
	int	i;

	i = 0;
	while (i < SCREENH)
	{
		if (i <= draw_s)
			cub->tv.adr_data[SCREENW * i + x] = cub->tv.ciel;
		else if (i <= draw_e)
		{
			cub->text.y = (int)cub->textpos;
			cub->textpos += cub->step;
			cub->tv.adr_data[SCREENW * i + x] = \
				cub->draw->adr_data[cub->draw->width * \
					cub->text.y + cub->text.x];
		}
		else if (i < SCREENH)
			cub->tv.adr_data[SCREENW * i + x] = cub->tv.floor;
		i++;
	}
}

void	drawtoscreen(t_cub *cub, int x)
{
	int	line_height;
	int	draw_s;
	int	draw_e;

	line_height = (int)(SCREENH / cub->walldistance);
	draw_s = -line_height / 2 + SCREENH / 2;
	if (draw_s < 0)
		draw_s = 0;
	draw_e = line_height / 2 + SCREENH / 2;
	if (draw_e >= SCREENH)
		draw_e = SCREENH - 1;
	cub->wallx = cub->postion.y + cub->walldistance * cub->raydirection.y;
	if (cub->whichside)
		cub->wallx = cub->postion.x + cub->walldistance * cub->raydirection.x;
	cub->wallx -= (int)cub->wallx;
	which_texture(cub);
	cub->step = (double)cub->draw->height / line_height;
	cub->textpos = (line_height / 2.0 - SCREENH / 2.0) * cub->step;
	if (line_height < SCREENH)
		cub->textpos = 0;
	draw_texture(cub, draw_s, draw_e, x);
}
