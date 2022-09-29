/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 05:44:47 by aklaikel          #+#    #+#             */
/*   Updated: 2022/09/29 04:14:00 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	dda_algorithm(t_cub *cub)
{
	cub->doorhit = false;
	while (cub->doorhit == false && \
		cub->data.map[cub->map.y][cub->map.x] != '1')
	{
		if (cub->whichwall.x < cub->whichwall.y)
		{
			cub->map.x += cub->whatdirection.x;
			cub->whichwall.x += cub->nextside.x;
			cub->whichside = 0;
		}
		else
		{
			cub->map.y += cub->whatdirection.y;
			cub->whichwall.y += cub->nextside.y;
			cub->whichside = 1;
		}
		if (cub->data.map[cub->map.y][cub->map.x] == 'D')
			cub->doorhit = true;
	}
}
