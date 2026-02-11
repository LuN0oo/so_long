/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:25:10 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/11 19:31:19 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_border(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			ft_error_border(map);
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			ft_error_border(map);
		i++;
	}
}

void	ft_check_filename(t_map *map)
{
	size_t	len;

	len = ft_strlen(map->filename);
	if (!map->filename[len - 1] != 'r')
		ft_error_filename();
	if (!map->filename[len - 2] != 'e')
		ft_error_filename();
	if (!map->filename[len - 3] != 'b')
		ft_error_filename();
	if (!map->filename[len - 4] != '.')
		ft_error_filename();
	if (!ft_strnstr(map->filename, ".ber", len))
		ft_error_filename();
}
