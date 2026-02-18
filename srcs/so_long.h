/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 01:03:16 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/18 19:03:15 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../GNL/get_next_line.h"
# include "../mlx/mlx.h"

/* ===== TO DELETE AT THE END ===== */

# include <stdio.h>

/* ===== TO DELETE AT THE END ===== */

/* ===== KEYCODE ===== */

# define ESC		53
# define UP
# define DOWN
# define LEFT
# define RIGHT
# define IMG_PXL	50
# define WDN_NAME	"so_long"

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
	int			p_count;
	int			e_count;
	int			e_check;
	int			c_count;
	int			c_check;
	int			moves;
	void		*mlx;
	void		*wdn;
}	t_map;

/* ===== Error Management ===== */

void	ft_error_filename(void);
void	ft_error_border(t_map *map);
void	ft_error_open(void);
void	ft_error_size(t_map *map);
void	ft_error_elements(t_map *map);

void	ft_check_map(t_map *map);
void	ft_check_border(t_map *map);
void	ft_check_size(t_map *map);
void	ft_check_element(t_map *map);
void	ft_check_filename(t_map *map);
void	ft_check_valid_path(t_map *map);
void	ft_move_on_path(int x, int y, t_map *map);
void	ft_scan_player(t_map *map);

/* ===== Free functions ===== */

int		ft_free_string(char **str, int i);
void	ft_free_exit(t_map *map);

/* ===== Parsing ===== */

void	ft_initialize(t_map *map, char **av);
void	ft_generate_map(t_map *map);
int		ft_count_lines(int fd);
char	*ft_read_file_content(int fd);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoinfree(char *s1, char *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *str);

#endif