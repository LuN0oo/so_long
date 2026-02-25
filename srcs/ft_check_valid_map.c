/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:25:10 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/25 18:16:36 by analaphi         ###   ########.fr       */
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
	if (map->filename[len - 1] != 'r')
		ft_error_filename();
	if (map->filename[len - 2] != 'e')
		ft_error_filename();
	if (map->filename[len - 3] != 'b')
		ft_error_filename();
	if (map->filename[len - 4] != '.')
		ft_error_filename();
	if (!ft_strnstr(map->filename, ".ber", len))
		ft_error_filename();
}

void	ft_check_size(t_map *map)
{
	int	y;
	int	x;
	int	max;

	y = 0;
	x = 0;
	max = ft_strlen(map->grid[y]);
	while (y < map->height)
	{
		x = ft_strlen(map->grid[y]);
		if (max != x)
			ft_error_size(map);
		y++;
	}
	map->width = max;
}

void	ft_check_element(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'C')
				map->c_count++;
			else if (map->grid[i][j] == 'P')
				map->p_count++;
			else if (map->grid[i][j] == 'E')
				map->e_count++;
			else if (map->grid[i][j] == '0' || map->grid[i][j] == '1')
				;
			else
				ft_error_elements(map);
			j++;
		}
		i++;
	}
	if (map->c_count < 1 || map->e_count < 1 || map->p_count != 1)
		ft_error_elements(map);
}

void	ft_check_map(t_map *map)
{
	ft_check_filename(map);
	ft_generate_map(map);
	ft_check_size(map);
	ft_check_border(map);
	ft_check_element(map);
	ft_check_valid_path(map);
	ft_free_string(map->copy, map->height);
}
