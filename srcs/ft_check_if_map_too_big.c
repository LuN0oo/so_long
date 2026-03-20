/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_map_too_big.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:49:53 by analaphi          #+#    #+#             */
/*   Updated: 2026/03/20 14:03:04 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_too_big(t_map *map)
{
	write(2, "\033[1;31mERROR: ", 14);
	write(2, "Map's too big!\n\033[0m", 19);
	if (map && map->grid)
	{
		ft_free_nl(map->grid);
		ft_free_nl(map->copy);
	}
	exit(EXIT_FAILURE);
}

void	ft_check_if_map_too_big(t_map *map)
{
	if ((map->height > 30) || (map->width > 60))
		ft_map_too_big(map);
}
