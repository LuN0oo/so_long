/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:34:26 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/18 16:45:26 by analaphi         ###   ########.fr       */
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
		//close window()
	else if (map->exit_check == 1)
		return (0);
	else if (keycode == UP)
		//move_up()
	else if (keycode == DOWN)
		//move_down()
	else if (keycode == LEFT)
		//move_left()
	else if (keycode == RIGHT)
		//move_right()
	return (0);
}