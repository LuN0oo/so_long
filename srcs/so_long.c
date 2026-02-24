/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:29:06 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/24 18:45:57 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize(t_map *map, char **av)
{
	map->filename = av[1];
	map->moves = 0;
	map->e_count = 0;
	map->c_count = 0;
	map->p_count = 0;
	map->height = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->exit = 0;
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
	{
		ft_initialize(&map, av);
		ft_check_map(&map);
		map.mlx = mlx_init();
		map.wdn = mlx_new_window(map.mlx, map.width
				* IMG_PXL, map.height * IMG_PXL, WDN_NAME);
		ft_file_to_image(&map);
		ft_print_map(&map);
		mlx_hook(map.wdn, 17, 0, ft_close, &map);
		mlx_key_hook(map.wdn, ft_keyhook, &map);
		mlx_loop(&map);
	}
	write(2, "\033[1;31mERROR: ", 14);
	write(2, "Format : ./so_long map.ber\n\033[0m", 30);
	exit(EXIT_FAILURE);
}
