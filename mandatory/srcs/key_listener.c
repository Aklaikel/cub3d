/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:15:30 by aklaikel          #+#    #+#             */
/*   Updated: 2022/09/29 05:34:44 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press(int key, t_cub *cub)
{
	if (key == ESC)
		return (ft_exit(cub));
	if (key == ROWLEFT)
		cub->smooth.rl = 1;
	if (key == ROWRIGHT)
		cub->smooth.rr = 1;
	if (key == FORWARD)
		cub->smooth.w = 1;
	if (key == BACKWARD)
		cub->smooth.s = 1;
	if (key == RIGHT)
		cub->smooth.d = 1;
	if (key == LEFT)
		cub->smooth.a = 1;
	return (0);
}

int	key_release(int key, t_cub *cub)
{
	if (key == ROWLEFT)
		cub->smooth.rl = 0;
	if (key == ROWRIGHT)
		cub->smooth.rr = 0;
	if (key == FORWARD)
		cub->smooth.w = 0;
	if (key == BACKWARD)
		cub->smooth.s = 0;
	if (key == RIGHT)
		cub->smooth.d = 0;
	if (key == LEFT)
		cub->smooth.a = 0;
	return (0);
}

void	key_listner(t_cub *cub)
{
	if (cub->smooth.w)
		move_forward(cub);
	if (cub->smooth.s)
		move_backward(cub);
	if (cub->smooth.d)
		move_right(cub);
	if (cub->smooth.a)
		move_left(cub);
	if (cub->smooth.rl)
	{	
		rotate_vec(&(cub->plan), &(cub->plan), -0.06);
		rotate_vec(&(cub->direction), &(cub->direction), -0.06);
	}
	if (cub->smooth.rr)
	{
		rotate_vec(&(cub->plan), &(cub->plan), 0.06);
		rotate_vec(&(cub->direction), &(cub->direction), 0.06);
	}
}
