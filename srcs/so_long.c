/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:29:06 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/11 17:07:20 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_initialize(int ac, char **av)
{
	
}

int	main(int ac, char **av)
{
	t_map map;

	if (ac != 2)
	{
		printf("Invalid Format.\n");
		return (1);
	}
	map.collectible_count = 0;
	map.exit_count = 0;
	map.player_count = 0;
	map.grid = NULL;
	if (!(ft_initialize_map(av[1], &map) < 0))
	{
		printf("Error when initializing map.\n");
		return (1);
	}
	printf("Map dimensions: %d x %d\n", map.height, map.width);
	printf("Player: %d\n", map.player_count);
	printf("Exit: %d\n", map.exit_count);
	printf("Collectibles: %d\n", map.collectible_count);
	if (ft_check_border(&map) < 0)
        printf("Borders are invalid!\n");
    else
		printf("Borders are valid.\n");
	return (0);
}
