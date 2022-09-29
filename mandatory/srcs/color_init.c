/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 05:46:32 by aklaikel          #+#    #+#             */
/*   Updated: 2022/09/29 04:14:36 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	colors(t_cub *cub)
{
	t_color	col;

	col.argb.a = 0;
	col.argb.r = cub->data.floor[0];
	col.argb.g = cub->data.floor[1];
	col.argb.b = cub->data.floor[2];
	cub->tv.floor = col.color;
	col.argb.r = cub->data.ceiling[0];
	col.argb.g = cub->data.ceiling[1];
	col.argb.b = cub->data.ceiling[2];
	cub->tv.ciel = col.color;
}
