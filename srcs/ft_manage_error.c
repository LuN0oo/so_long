/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:29:01 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/11 19:34:04 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_filename(void)
{
	write(2, "\033[1;31mERROR: ", 14);
	write(2, "Filename should be a BER extension file.\n\033[0m", 45);
	exit(EXIT_FAILURE);
}

void	ft_error_border(t_map *map)
{
	write(2, "\033[1;31mERROR: ", 14);
	write(2, "The borders are not valid.\n\033[0m", 31);
	ft_free_string(map->grid, map->height);
	ft_free_string(map->copy, map->height);
	exit(EXIT_FAILURE);
}

void	ft_error_open(void)
{
	write(2, "\033[1;31mERROR: ", 14);
	write(2, "Failed opening the file.\n\033[0m", 29);
	exit(EXIT_FAILURE);
}

void	ft_error_size(t_map *map)
{
	write(2, "\033[1;31mERROR: ", 14);
	write(2, "Wrong size.\n\033[0m", 16);
	ft_free_string(map->grid, map->height);
	ft_free_string(map->copy, map->height);
	exit(EXIT_FAILURE);
}

void	ft_error_elements(t_map *map)
{
	write(2, "\033[1;31mERROR: ", 14);
	write(2, "Wrong number of elements in the map.\n\033[0m", 41);
	ft_free_string(map->grid, map->height);
	ft_free_string(map->copy, map->height);
	exit(EXIT_FAILURE);
}
