/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_ready.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 01:09:56 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/18 17:06:28 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_generate_map(t_map *map)
{
	int	fd;

	map->height = 0;
	map->line = "";
	map->file = NULL;
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		ft_error_open();
	while (map->line)
	{
		map->line = get_next_line(fd);
		if (map->line == NULL)
			break ;
		map->file = ft_strjoinfree(map->file, map->line);
		free(map->line);
		if (!map->file)
			ft_free_exit(map);
		map->height++;
	}
	close(fd);
	map->grid = ft_split(map->file, '\n');
	map->copy = ft_split(map->file, '\n');
	if (!map->grid || !map->copy)
		ft_free_exit(map);
	free(map->file);
}
