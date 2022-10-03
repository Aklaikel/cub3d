/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_pase_map2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamd <ael-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:21:24 by ael-hamd          #+#    #+#             */
/*   Updated: 2022/10/03 18:53:43 by ael-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_first_last_line(char	*str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	get_last_line(t_data data)
{
	int	last;
	int	i;
	int	j;

	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == '1')
			{
				last = i;
				break ;
			}
			j++;
		}
		i++;
	}
	return (last);
}

int	check_element(char	*str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c != ' ' && c != '1' && c != '0'
			&& c != 'N' && c != 'S' && c != 'W' && c != 'E')
			return (0);
		i++;
	}
	return (1);
}

static	int	ft_returne(int count)
{
	if (count != 1)
	{
		printf("Error\nPlayer Problem !!");
		return (0);
	}
	return (1);
}

int	check_player(t_data *data)
{
	int		i;
	int		j;
	int		count;
	char	c;

	i = 0;
	count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			c = data->map[i][j];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				count++;
				data->y = i;
				data->x = j;
				data->direction = c;
			}
			j++;
		}
		i++;
	}
	return (ft_returne(count));
}
