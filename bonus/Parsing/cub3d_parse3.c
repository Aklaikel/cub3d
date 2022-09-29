/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamd <ael-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:44:13 by ael-hamd          #+#    #+#             */
/*   Updated: 2022/09/29 22:38:55 by ael-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_alloc(char **str1, char *str2, int size)
{
	if (*str1 != NULL)
	{
		printf("Error\nDouble Element");
		return (0);
	}
	*str1 = malloc(size);
	if (!str1)
		return (0);
	while (*str2 == ' ')
		str2++;
	ft_strcpy(*str1, str2);
	return (1);
}

int	alloc_str(char *s, t_data *data, char d, int size)
{
	int	k;

	k = 0;
	if (d == 'N')
		k = ft_alloc(&(data->no), s, size);
	else if (d == 'S')
		k = ft_alloc(&(data->so), s, size);
	else if (d == 'W')
		k = ft_alloc(&(data->we), s, size);
	else if (d == 'E')
		k = ft_alloc(&(data->ea), s, size);
	else if (d == 'F' || d == 'C')
			k = check_color(s, data, d);
	return (k);
}

int	if_color(char *s)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == ',')
			k++;
		if ((s[i] != ',' && !ft_isdigit(s[i])) || k > 2)
			return (0);
		i++;
	}
	if (k < 2)
		return (0);
	return (1);
}

void	str_cpy_2d(char **str, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		data->map[i] = malloc(sizeof(char *) * max_lenght(str) + 1);
		j = 0;
		while (str[i][j])
		{
			data->map[i][j] = str[i][j];
			j++;
		}
		while (j < max_lenght(str))
		{
			data->map[i][j] = ' ';
			j++;
		}
		data->map[i][j] = '\0';
		i++;
	}
	data->height = i;
	data->width = max_lenght(str);
	data->map[i] = NULL;
}

int	get_map(char **file, t_data *data)
{
	int	k;
	int	size;

	k = pos_map(file);
	if (k > 0 && k < ft_strlen_2d(file) - 1)
	{
		size = ft_strlen_2d(file) - k;
		data->map = malloc((sizeof(char **) * size) + 1);
		str_cpy_2d(file + k, data);
		return (1);
	}
	else
	{
		printf("Error\nMap does not exist\n");
		return (0);
	}
}
