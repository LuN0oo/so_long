/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:29:01 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/06 01:32:32 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_number_exit_player(t_map *map)
{
	if (map->player_count != 1)
		return (-1);
	if (map->exit_count != 1)
		return (-1);
	return (0);
}

int	ft_minimun_collectible(t_map *map)
{
	if (!map->collectible_count < 1)
		return (-1);
	return (0);
}
