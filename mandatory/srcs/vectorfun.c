/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorfun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 05:40:12 by aklaikel          #+#    #+#             */
/*   Updated: 2022/09/28 10:18:03 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_vec(t_vector *dst, t_vector *vctr, t_angle teta)
{
	double	x;
	double	y;

	x = vctr->x;
	y = vctr->y;
	dst->x = x * cos(teta) + y * sin(teta);
	dst->y = -x * sin(teta) + y * cos(teta);
}

void	multiple_vec_nbr(t_vector *vctr, t_angle multi)
{
	vctr->x = multi * vctr->x;
	vctr->y = multi * vctr->y;
}
