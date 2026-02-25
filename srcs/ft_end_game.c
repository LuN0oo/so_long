/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:29:26 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/25 18:41:26 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_map *map)
{
	if (map->img.floor)
		mlx_destroy_image(map->mlx, map->img.floor);
	if (map->img.wall)
		mlx_destroy_image(map->mlx, map->img.wall);
	if (map->img.player)
		mlx_destroy_image(map->mlx, map->img.player);
	if (map->img.strawberry)
		mlx_destroy_image(map->mlx, map->img.strawberry);
	if (map->img.heart)
		mlx_destroy_image(map->mlx, map->img.heart);
	mlx_destroy_window(map->mlx, map->wdn);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	ft_free_string(map->grid, map->height);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_win(t_map *map)
{
	map->exit = 1;
	map->moves++;
	mlx_clear_window(map->mlx, map->wdn);
	mlx_string_put(map->mlx, map->wdn,
		map->width / 2 * IMG_PXL, map->height / 2 * IMG_PXL,
		0xFFFA9E, "YOU WON");
	write(1, "\n", 1);
	write(1, "\x1b[32;01m", 9);
	write(1, "YOU WON!\n", 9);
	write(1, "\x1b[0m", 5);
}
