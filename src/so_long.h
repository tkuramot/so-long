/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:00:30 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/19 18:26:45 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>

# define BLOCK_SIZE 32
# define EMPTY_PATH "./textures/tiles/empty.xpm"
# define WALL_PATH "./textures/tiles/wall.xpm"
# define COLLECTIBLE_PATH "./textures/tiles/collectible.xpm"
# define EXIT_PATH "./textures/tiles/wall.xpm"
# define PLAYER_PATH "./textures/sprites/player.xpm"

typedef enum e_char {
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}			t_char;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_map
{
	char	**grid;
	size_t	row;
	size_t	column;
}				t_map;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_textures
{
	void	*empty;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
}				t_textures;

t_map			*parse_map(char *map_file);
bool			is_valid_map(t_map *map);
bool			is_surrounded_by_walls(t_map *map);
bool			is_playable(t_map *map);
t_textures		*load_textures(t_vars	*vars);
void			put_map_to_window(t_vars *vars, t_textures *textures, t_map *map);
t_point			get_point(int x, int y);
void			**calloc_2d_array(size_t n_2d, size_t n_1d, size_t siz);
void			free_2d_array(void **array, size_t n);

#endif