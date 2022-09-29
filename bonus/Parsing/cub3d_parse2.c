/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamd <ael-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:39:34 by ael-hamd          #+#    #+#             */
/*   Updated: 2022/09/29 14:17:24 by ael-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_path(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int	max_lenght(char **s)
{
	int	max;
	int	i;

	i = 1;
	max = ft_strlen(s[0]);
	while (s[i])
	{
		if (ft_strlen(s[i]) > max)
			max = ft_strlen(s[i]);
		i++;
	}
	return (max);
}

static	int	ft_rempl_colors(char **c, t_data *data, char d)
{
	int	k;
	int	i;

	i = 0;
	while (i < 3)
	{
		k = ft_atoi(c[i]);
		if (k >= 0 && k <= 255)
		{
			if (d == 'F')
				data->floor[i] = k;
			else
				data->ceiling[i] = k;
		}
		else
		{
			printf("Error\nInvalid Color !!");
			ft_free(c);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_color(char *s, t_data *data, char d)
{
	char	**c;

	if ((d == 'F' && data->floor[0] > -1)
		|| (d == 'C' && data->ceiling[0] > -1))
	{
		printf("Error\nDouble Color");
		return (0);
	}
	c = ft_split(s, ',');
	if (ft_strlen_2d(c) < 3)
	{
		ft_free(c);
		printf("Error\nInvalide Colors\n");
		return (0);
	}
	if (!ft_rempl_colors(c, data, d))
		return (0);
	ft_free(c);
	return (1);
}
