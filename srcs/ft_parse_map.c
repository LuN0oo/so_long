/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:01:16 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/06 01:21:04 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_split_map(char *content, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			j++;
		i++;
	}
	map->height = j + 1;
	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	map->width = i;
	return (0);
}

int	ft_count_element(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'C')
				map->collectible_count++;
			else if (map->grid[i][j] == 'P')
				map->player_count++;
			else if (map->grid[i][j] == 'E')
				map->exit_count++;
			j++;
		}
		i++;
	}
	return (0);
}
