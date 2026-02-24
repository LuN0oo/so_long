/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:45:35 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/24 18:45:09 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_update_move(t_map *map, int x, int y, int dir)
{
	if (dir == UP)
		y -= 1;
	if (dir == DOWN)
		y += 1;
	if (dir == LEFT)
		x -= 1;
	if (dir == RIGHT)
		x += 1;
	if (map->grid[y][x] == 'E' && map->c_count)
		return (ft_win(map));
	if (map->grid[y][x] == 'C')
	{
		map->grid[y][x] = '0';
		map->c_count--;
	}
}

void	ft_move_up(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y > 0 && map->grid[y - 1][x] != '1')
	{
		ft_update_move(map, x, y, UP);
		if (map->grid[y - 1][x] == 'E' && (map->c_count != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.floor,
			x * IMG_PXL, y * IMG_PXL);
		map->grid[y][x] = '0';
		y--;
		ft_print_nb_move(map);
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.floor,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.player,
			x * IMG_PXL, y * IMG_PXL);
		map->grid[y][x] = 'P';
		map->player.x = x;
	}
}

void	ft_move_down(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y < map->height && map->grid[y + 1][x] != '1')
	{
		ft_update_move(map, x, y, DOWN);
		if (map->grid[y + 1][x] == 'E' && (map->c_count != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.floor,
			x * IMG_PXL, y * IMG_PXL);
		map->grid[y][x] = '0';
		y++;
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.floor,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.player,
			x * IMG_PXL, y * IMG_PXL);
		map->grid[y][x] = 'P';
		ft_print_nb_move(map);
		map->player.y = y;
	}
}

void	ft_move_left(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x > 0 && map->grid[y][x - 1] != '1')
	{
		ft_update_move(map, x, y, LEFT);
		if (map->grid[y][x - 1] == 'E' && (map->c_count != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.floor,
			x * IMG_PXL, y * IMG_PXL);
		map->grid[y][x] = '0';
		x--;
		ft_print_nb_move(map);
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.floor,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.player,
			x * IMG_PXL, y * IMG_PXL);
		map->grid[y][x] = 'P';
		map->player.y = y;
	}
}

void	ft_move_right(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x < map->width && map->grid[y][x + 1] != '1')
	{
		ft_update_move(map, x, y, RIGHT);
		if (map->grid[y][x + 1] == 'E' && (map->c_count != 0 || map->exit == 1))
			return ;
		map->moves++;
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.floor,
			x * IMG_PXL, y * IMG_PXL);
		map->grid[y][x] = '0';
		x++;
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.floor,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.player,
			x * IMG_PXL, y * IMG_PXL);
		map->grid[y][x] = 'P';
		ft_print_nb_move(map);
	}
	map->player.x = x;
}
