/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamd <ael-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:40:00 by ael-hamd          #+#    #+#             */
/*   Updated: 2022/10/03 18:26:17 by ael-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

static int	checknm(char *s)
{
	return (strncmp(s + strlen(s) - 4, ".cub", 4));
}

int	main(int ac, char **av)
{
	t_data	data;
	char	**file;

	if (ac != 2)
		return (printf("Error\nBad Arguments\nPlease input axec + map file"), 0);
	if (checknm(av[1]))
		return (printf("Error\nname error please file must end with .cub"), 0);
	file = ft_read(open(av[1], O_RDONLY));
	if (!file)
		return (1);
	ft_null(&data);
	if (!rempl_description_map(file, &data))
		return (ft_free(file), 0);
	if (!data.so || !data.ea || !data.no || !data.we)
		return (printf("Error\ntexture Not valide !!\n"), 0);
	if (!get_map(file, &data))
		return (ft_free(file), 0);
	if (!check_map(data))
		return (0);
	if (!check_player(&data))
		return (ft_free(file), 0);
	raycastcub3d(data);
	ft_free(file);
	ft_free_all(&data);
	return (0);
}
