/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:34:26 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/24 18:45:39 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_scan_player(t_map *map)
{
	map->player.y = 0;
	map->player.x = 0;
	while (map->player.y < map->height)
	{
		while (map->player.x < map->width)
		{
			if (map->grid[map->player.y][map->player.x] == 'P')
				break ;
			map->player.x++;
		}
		if (map->grid[map->player.y][map->player.x] == 'P')
			break ;
		map->player.x = 0;
		map->player.y++;
	}
}

int	ft_keyhook(int keycode, t_map *map)
{
	ft_scan_player(map);
	if (keycode == ESC)
		return (ft_close(map));
	else if (map->exit == 1)
		return (0);
	else if (keycode == UP)
		ft_move_up(map);
	else if (keycode == DOWN)
		ft_move_down(map);
	else if (keycode == LEFT)
		ft_move_left(map);
	else if (keycode == RIGHT)
		ft_move_right(map);
	return (0);
}
