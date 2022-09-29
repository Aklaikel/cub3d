/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_pase_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamd <ael-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:14:27 by ael-hamd          #+#    #+#             */
/*   Updated: 2022/09/29 19:48:06 by ael-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_first_last(t_data data, int i, int j, int last)
{
	if (((i == 0 || i == last) && ! check_first_last_line(data.map[i]))
		|| !check_element(data.map[i]) || data.map[i][j] == '0')
	{
		printf("Error\nMap invalide");
		return (1);
	}
	return (0);
}

int	ft_check_zero(t_data data, int i, int j)
{
	if (!data.map[i][j + 1] || data.map[i][j + 1] == ' '
			|| data.map[i + 1][j] == ' ' ||
			data.map[i - 1][j] == ' ' || data.map[i][j - 1] == ' ')
	{
		printf("Error\nMap problem");
		return (1);
	}
	return (0);
}

int	check_map(t_data data)
{
	int		i;
	int		j;

	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j] && (data.map[i][j] == ' '
			|| data.map[i][j] == '\t'))
			j++;
		if (ft_check_first_last(data, i, j, get_last_line(data)))
			return (0);
		while (data.map[i][j])
		{
			if (data.map[i][j] == '0')
			{
				if (ft_check_zero(data, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
