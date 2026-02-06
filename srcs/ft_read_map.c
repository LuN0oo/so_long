/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:36:17 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/06 01:19:00 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_lines(int fd)
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

char	*ft_read_file_content(int fd)
{
	char	*content;
	int		i;
	int		byte_read;

	i = 0;
	content = malloc(1);
	if (!content)
		return (NULL);
	content[0] = '\0';
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
