/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:09:14 by aklaikel          #+#    #+#             */
/*   Updated: 2022/10/03 21:29:18 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_forward(t_cub *cub)
{
	double	tmpx;
	double	tmpy;

	tmpx = cub->postion.x + (cub->direction.x * .08);
	tmpy = cub->postion.y + (cub->direction.y * .08);
	if (cub->data.map[(int)tmpy][(int)tmpx] == '0')
	{
		cub->postion.x = tmpx;
		cub->postion.y = tmpy;
	}
}

void	move_backward(t_cub *cub)
{
	double	tmpx;
	double	tmpy;

	tmpx = cub->postion.x - (cub->direction.x * .08);
	tmpy = cub->postion.y - (cub->direction.y * .08);
	if (cub->data.map[(int)tmpy][(int)tmpx] == '0')
	{
		cub->postion.x = tmpx;
		cub->postion.y = tmpy;
	}
}

void	move_right(t_cub *cub)
{
	double		tmpx;
	double		tmpy;
	t_vector	tmpvec;

	tmpvec.x = cub->direction.x;
	tmpvec.y = cub->direction.y;
	rotate_vec(&(tmpvec), &(tmpvec), M_PI / 2);
	tmpx = cub->postion.x + (tmpvec.x * 0.06);
	tmpy = cub->postion.y + (tmpvec.y * 0.06);
	if (cub->data.map[(int)tmpy][(int)tmpx] == '0')
	{
		cub->postion.x = tmpx;
		cub->postion.y = tmpy;
	}
}

void	move_left(t_cub *cub)
{
	double		tmpx;
	double		tmpy;
	t_vector	tmpvec;

	tmpvec.x = cub->direction.x;
	tmpvec.y = cub->direction.y;
	rotate_vec(&(tmpvec), &(tmpvec), M_PI / 2);
	tmpx = cub->postion.x - (tmpvec.x * 0.06);
	tmpy = cub->postion.y - (tmpvec.y * 0.06);
	if (cub->data.map[(int)tmpy][(int)tmpx] == '0')
	{
		cub->postion.x = tmpx;
		cub->postion.y = tmpy;
	}
}

int	ft_exit(t_cub *cub)
{
	if (cub->ea.image)
		mlx_destroy_image(cub->mlx_ptr, cub->ea.image);
	if (cub->we.image)
		mlx_destroy_image(cub->mlx_ptr, cub->we.image);
	if (cub->so.image)
		mlx_destroy_image(cub->mlx_ptr, cub->so.image);
	if (cub->no.image)
		mlx_destroy_image(cub->mlx_ptr, cub->no.image);
	free(cub);
	exit(0);
}
