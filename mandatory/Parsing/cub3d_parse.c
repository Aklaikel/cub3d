/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamd <ael-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:23:38 by ael-hamd          #+#    #+#             */
/*   Updated: 2022/10/03 16:25:34 by ael-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_atoi(char *str)
{
	long	res;

	res = 0;
	while (*str == ' ')
		str++;
	if (*str == '\0' || *str == '-')
		return (-1);
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	if (res > 2147483647)
		return (-1);
	return ((int)res);
}

void	ft_strcpy(char *dir, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		dir[i] = s[i];
		i++;
	}
	dir[i] = '\0';
}

char	**ft_read(int fd)
{
	int		n;
	char	buff[BUFFER_SIZE];

	if (fd < 0)
	{
		perror("Error :");
		return (0);
	}
	n = read(fd, buff, BUFFER_SIZE);
	if (n == 0)
	{
		printf("Error\nEmpty file");
		exit(1);
	}
	if (n == -1)
		return (0);
	buff[n] = '\0';
	return (ft_split(buff, '\n'));
}

int	pos_map(char **file)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			if (file[i][j] != ' ' && file[i][j] != '1' && file[i][j] != '0')
			{
				k = 0;
				break ;
			}
			else
				k = 1;
			j++;
		}
		if (k)
			return (i);
		i++;
	}
	return (-1);
}

char	get_directions(char	*s)
{
	int	len;

	len = ft_strlen(s);
	if (len > 3)
	{
		if (s[0] == 'N' && s[1] == 'O' && s[2] == ' ')
			return ('N');
		else if (s[0] == 'S' && s[1] == 'O' && s[2] == ' ')
			return ('S');
		else if (s[0] == 'W' && s[1] == 'E' && s[2] == ' ')
			return ('W');
		else if (s[0] == 'E' && s[1] == 'A' && s[2] == ' ')
			return ('E');
		else if (s[0] == 'F' && s[1] == ' ')
			return ('F');
		else if (s[0] == 'C' && s[1] == ' ')
			return ('C');
	}
	return (' ');
}
