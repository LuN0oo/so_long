/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_ready.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 01:09:56 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/06 01:32:48 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_initialize_map(char *filename, t_map *map)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	map->grid = ft_read_file_content(fd);
	if (!map->grid)
		return (-1);
	close(fd);
	ft_split_map(map->grid, map);
	ft_count_element(map);
	if (ft_number_exit_player(map) < 0 || ft_minimun_collectible(map) < 0)
		return (-1);
	if (ft_check_border(map) < 0)
		return (-1);
	return (0);
}
