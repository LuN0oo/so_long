/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:29:06 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/11 21:40:51 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_initialize(t_map *map, char **av)
{
	map->filename = av[1];
	map->moves = 0;
	map->exit_count = 0;
	map->collectible_count = 0;
	map->player_count = 0;
	map->player.x = 0;
	map->player.y = 0;
}

int	main(int ac, char **av)
{
	t_map *map;

	if (ac == 2)
	{
		ft_initialize(&map, av);
		ft_check_map(&map);
	}
}
