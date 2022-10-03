/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_tools2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:55:08 by ael-hamd          #+#    #+#             */
/*   Updated: 2022/10/03 21:32:24 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen_2d(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_null(t_data *data)
{
	int	i;

	i = 0;
	data->ea = NULL;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	while (i < 3)
	{
		data->floor[i] = -1;
		data->ceiling[i] = -1;
		i++;
	}
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
