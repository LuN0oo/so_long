/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:09:54 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/18 16:55:32 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_on_path(int x, int y, t_map *map)
{
	char type;

	type = map->copy[y][x];
	if (type == 'C')
	{
		map->collectible_check -= 1;
		map->copy[y][x] = '1';	
	}
	else if (type == 'E')
	{
		map->exit_check -= 1;
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
