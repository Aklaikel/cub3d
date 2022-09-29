/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 05:20:49 by aklaikel          #+#    #+#             */
/*   Updated: 2022/09/29 05:35:12 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	_free_(t_cub *cub)
{
	free(cub);
	if (cub->no.image)
		mlx_destroy_image(cub->mlx_ptr, cub->no.image);
	if (cub->so.image)
		mlx_destroy_image(cub->mlx_ptr, cub->so.image);
	if (cub->ea.image)
		mlx_destroy_image(cub->mlx_ptr, cub->ea.image);
	if (cub->we.image)
		mlx_destroy_image(cub->mlx_ptr, cub->we.image);
	if (cub->tv.image)
		mlx_destroy_image(cub->mlx_ptr, cub->tv.image);
	if (cub->mlx_window)
		mlx_destroy_window(cub->mlx_ptr, cub->mlx_window);
}
