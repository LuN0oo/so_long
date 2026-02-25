/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:08:17 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/25 17:45:11 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_file_to_image(t_map *map)
{
	int	a;

	a = IMG_PXL;
	map->img.player = mlx_xpm_file_to_image(map->mlx,
			"textures/Player.xpm", &a, &a);
	map->img.strawberry = mlx_xpm_file_to_image(map->mlx,
			"textures/Strawberry.xpm", &a, &a);
	map->img.heart = mlx_xpm_file_to_image(map->mlx,
			"textures/Exit.xpm", &a, &a);
	map->img.wall = mlx_xpm_file_to_image(map->mlx,
			"textures/Wall.xpm", &a, &a);
	map->img.floor = mlx_xpm_file_to_image(map->mlx,
			"textures/Ground.xpm", &a, &a);
}
