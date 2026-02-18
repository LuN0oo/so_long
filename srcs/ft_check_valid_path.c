/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:09:54 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/18 17:06:59 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_on_path(int x, int y, t_map *map)
{
	char	type;

	type = map->copy[y][x];
	if (type == 'C')
	{
		map->c_check -= 1;
		map->copy[y][x] = '1';
	}
	else if (type == 'E')
	{
		map->e_check -= 1;
		map->copy[y][x] = '1';
	}
	else if (type == '0' || type == 'P')
		map->copy[y][x] == '1';
	else
		return ;
	ft_move_on_path(x + 1, y, map);
	ft_move_on_path(x - 1, y, map);
	ft_move_on_path(x, y + 1, map);
	ft_move_on_path(x, y - 1, map);
}

void	check_valid_path(t_map *map)
{
	map->c_check = map->c_count;
	map->e_check = map->e_count;
	ft_scan_player(map);
	ft_move_on_path(map->player.x, map->player.y, map);
	if (map->c_check != 0 || map->e_check >= map->e_count)
	{
		write(2, "\033[1;31mERROR: ", 14);
		write(2, "There's no valid path on the map.\n\033[0m", 38);
		ft_free_string(map->grid, map->height);
		ft_free_string(map->copy, map->height);
		exit(EXIT_FAILURE);
	}
}
