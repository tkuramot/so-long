/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:00:30 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/21 00:48:22 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

# define BLOCK_SIZE 32
# define EMPTY_PATH "./textures/tiles/empty.xpm"
# define WALL_PATH "./textures/tiles/wall.xpm"
# define COLLECTIBLE_PATH "./textures/tiles/collectible.xpm"
# define EXIT_PATH "./textures/tiles/exit.xpm"
# define PLAYER_PATH "./textures/sprites/player.xpm"

typedef enum	e_char {
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}				t_char;

typedef enum	e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}				t_event;

typedef enum	e_keycode
{
	ESC = 65307,
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100
}				t_keycode;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_coord
{
	long long	y;
	long long	x;
}			t_coord;

typedef struct s_map
{
	char	**grid;
	size_t	row;
	size_t	column;
}				t_map;

typedef struct s_textures
{
	void	*empty;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
}				t_textures;

typedef struct s_game
{
	t_vars		vars;
	t_map		*map;
	t_textures	textures;
	t_coord		player;
}				t_game;

t_map			*parse_map(char *map_file);
void			initilizePlayerCoord(t_game *game);
bool			is_valid_map(t_map *map);
bool			is_surrounded_by_walls(t_map *map);
bool			is_playable(t_map *map);
bool			load_textures(t_game *game);
int				draw_all(t_game *game);
int				event_handler(int keycode, t_game *game);
int				my_close(t_vars *vars);
void			**calloc_2d_array(size_t n_2d, size_t n_1d, size_t siz);
void			free_2d_array(void **array, size_t n);
t_coord			find_chr_in_map(t_map *map, char c);
bool			is_same_coord(t_coord c1, t_coord c2);
void			replace_newline_with_null(char *s);

#endif