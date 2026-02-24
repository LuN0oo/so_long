/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:29:30 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/24 20:05:46 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_print_element(t_map *map, int x, int y)
{
	int	elem;

	elem = map->grid[y / IMG_PXL][x / IMG_PXL];
	if (elem == 'C' || elem == 'P' || elem == 'E' || elem == '0')
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.floor, x, y);
	if (elem == 'C')
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.strawberry, x, y);
	else if (elem == 'P')
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.player, x, y);
	else if (elem == 'E')
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.heart, x, y);
	else if (elem == '1')
		mlx_put_image_to_window(map->mlx, map->wdn, map->img.wall, x, y);
}

void	ft_print_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			ft_print_element(map, x * IMG_PXL, y * IMG_PXL);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_print_nb_move(t_map *map)
{
	char	*move;

	move = ft_itoa(map->moves);
	write(1, "\r", 1);
	write(1, "\x1b[33;01m", 9);
	write(1, move, ft_strlen(move));
	write(1, "\x1b[0m", 5);
	write(1, " moves", 6);
	free(move);
}
