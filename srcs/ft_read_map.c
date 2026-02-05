/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:36:17 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/05 18:13:51 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count_lines(int fd)
{
	int		byte_read;
	char	c;
	int		count;

	count = 0;
	byte_read = read(fd, &c, 1);
	while (byte_read > 0)
	{
		if (c == '\n')
			count++;
		byte_read = read(fd, &c, 1);
	}
	return (count + 1);
}

static char *read_file_content(int fd)
{
	char	*content;
	int		i;
	int		byte_read;

	i = 0;
	content = malloc(1);
	if (!content)
		return (NULL);
	content[0] == '\0';
	byte_read = read(fd, &content[i], 1);
	while (byte_read > 0)
	{
		i++;
		content = malloc(i + 1);
		if (!content)
			return (NULL);
		content[i] = '\0';
		byte_read = read(fd, &content[i], 1);
	}
	return (content);
}

static int split_map(char *content, t_map *map)
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
	return (0);
}

int	read_map(char *filename, t_map *map)
{
	
}