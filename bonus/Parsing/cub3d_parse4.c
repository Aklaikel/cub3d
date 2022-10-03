/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamd <ael-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:14:18 by ael-hamd          #+#    #+#             */
/*   Updated: 2022/10/03 16:01:33 by ael-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_variables(t_data *data)
{
	if (!data->so || !data->ea || !data->no || !data->we)
	{
		printf("Error\ntexture Not valide !!\n");
		return (0);
	}
	if (data->floor[0] < 0 || data->floor[1] < 0 || data->floor[2] < 0
		|| data->ceiling[0] < 0 || data->ceiling[1] < 0 || data->ceiling[2] < 0)
	{
		printf("Error\nColors Not valide !!\n");
		return (0);
	}
	return (1);
}

int	ft_check_alloc(char **file, t_data *data, char d, int i)
{
	int		k;

	if ((d == 'F' || d == 'C') && if_color(file[i] + 2))
			k = alloc_str(file[i] + 2, data,
				d, ft_strlen(file[i]) - 2);
	else if ((d == 'N' || d == 'S' || d == 'W' || d == 'E'))
		k = alloc_str(file[i] + 3, data, d, ft_strlen(file[i]) - 2);
	else
	{
		printf("Error\nMap Error\n");
		return (0);
	}
	if (!k)
		return (0);
	return (1);
}

int	rempl_description_map(char **file, t_data *data)
{
	int		i;
	char	d;

	i = 0;
	while (file[i])
	{
		if (check_first_last_line(file[i]))
			break ;
		d = get_directions(file[i]);
		if (d != ' ' && ft_strlen(file[i]) > 2)
		{
			if (!ft_check_alloc(file, data, d, i))
				return (0);
		}
		else
		{
			if (ft_strlen(file[i]) > 0 && !check_first_last_line(file[i]))
			{
				printf("Error\nDescription Problem\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}
