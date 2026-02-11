/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:24:29 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/11 19:31:32 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_string(char **str, int i)
{
	while (i > 0)
		free(str[--i]);
	free(str);
	return (0);
}

void	ft_free_exit(t_map *map)
{
	if (map->grid)
		free(map->grid);
	if (map->copy)
		free(map->copy);
	if (map->file)
		free(map->file);
	if (map->line)
		free(map->line);
	exit(EXIT_FAILURE);
}
