/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 01:03:16 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/12 11:46:57 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../GNL/get_next_line.h"

/* ===== TO DELETE AT THE END ===== */

# include <stdio.h>

/* ===== TO DELETE AT THE END ===== */

/* ===== Map Struct ===== */

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_img
{
	void	*player_sprite;
	void	*strawberry_sprite;
	void	*closed_exit_sprite;
	void	*opened_exit_sprite;
	void	*wall_sprite;
	void	*floor_sprite;
}	t_img;

typedef struct s_map
{
	t_player	player;
	t_img		img;
	char		*filename;
	char		*file;
	char		*line;
	char		**grid;
	char		**copy;
	int			fd;
	int			width;
	int			height;
	int			player_count;
	int			exit_count;
	int			exit_check;
	int			collectible_count;
	int			collectible_check;
	int			moves;
	void		*mlx;
	void		*win;
}	t_map;

/* ===== Error Management ===== */

void	ft_error_filename(void);
void	ft_error_border(t_map *map);
void	ft_error_open(void);
void	ft_error_size(t_map *map);
void	ft_error_elements(t_map *map);

void	ft_check_map(t_map *map);
int		ft_check_border(t_map *map);
void	ft_check_filename(t_map *map);

/* ===== Free functions ===== */

int		ft_free_string(char **str, int i);
void	ft_free_exit(t_map *map);

/* ===== Parsing ===== */

int		ft_initialize_map(char *filename, t_map *map);
int		ft_count_lines(int fd);
char	*ft_read_file_content(int fd);
int		ft_split_map(char *content, t_map *map);
int		ft_count_element(t_map *map);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif