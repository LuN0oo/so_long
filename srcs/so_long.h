/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 01:03:16 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/06 01:31:48 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/* ===== TO DELETE AT THE END ===== */

# include <stdio.h>

/* ===== TO DELETE AT THE END ===== */

/* ===== Map Struct ===== */

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_count;
	int		exit_count;
	int		collectible_count;
}	t_map;

/* ===== Game Struct ===== */

typedef struct s_game
{
	t_map	map;
	void	*mlx;
	void	*win;
	int		player_pos_x;
	int		player_pos_y;
	int		moves;
	int		collected;
	void	*player_sprite;
	void	*strawberry_sprite;
	void	*closed_exit_sprite;
	void	*opened_exit_sprite;
	void	*wall_sprite;
	void	*floor_sprite;
}	t_game;

/* ===== Error Management ===== */

void	ft_error(void);
int		ft_number_exit_player(t_map *map);
int		ft_minimun_collectible(t_map *map);

/* ===== Parsing ===== */

int		ft_count_lines(int fd);
char	*ft_read_file_content(int fd);
int		ft_split_map(char *content, t_map *map);
int		ft_count_element(t_map *map);
int		ft_check_border(t_map *map);

#endif