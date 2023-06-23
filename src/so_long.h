/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:00:30 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/23 23:06:38 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <sys/errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <string.h>

# define BLOCK_SIZE 32
# define EMPTY_PATH "./textures/tiles/empty.xpm"
# define WALL_PATH "./textures/tiles/wall.xpm"
# define COLLECTIBLE_PATH "./textures/tiles/collectible.xpm"
# define EXIT_PATH "./textures/tiles/exit.xpm"
# define PLAYER1_PATH "./textures/sprites/player1.xpm"
# define PLAYER2_PATH "./textures/sprites/player2.xpm"
# define PLAYER_FRAME 2
# define ENEMY1_PATH "./textures/sprites/enemy1.xpm"
# define ENEMY2_PATH "./textures/sprites/enemy2.xpm"
# define ENEMY3_PATH "./textures/sprites/enemy3.xpm"
# define ENEMY4_PATH "./textures/sprites/enemy4.xpm"
# define ENEMY_FRAME 4

typedef enum	e_char
{
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}				t_char;

typedef enum	e_idx_texture
{
	IDX_EMPTY,
	IDX_WALL,
	IDX_COLLECTIBLE,
	IDX_EXIT,
	IDX_PLAYER1,
	IDX_PLAYER2,
	IDX_ENEMY1,
	IDX_ENEMY2,
	IDX_ENEMY3,
	IDX_ENEMY4
}				t_idx_texture;


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
	size_t	counter;
	void	*containers[10];
}				t_textures;

typedef struct s_game
{
	size_t		move;
	t_vars		vars;
	t_map		map;
	t_textures	textures;
	t_coord		player;
	t_coord		enemy;
}				t_game;

bool			parse_map(t_game *game, char *map_file);
bool			is_valid_map(t_map *map);
bool			is_surrounded_by_walls(t_map *map);
bool			is_playable(t_map *map);
bool			load_textures(t_game *game);
int				draw_all(t_game *game);
void			put_sprite_with_animation(t_game *game);
void			put_texture_to_window(t_vars *vars, void *img, t_coord coord);
int				event_handler(int keycode, t_game *game);
int				my_close(t_game *game);
void			**calloc_2d_array(size_t n_2d, size_t n_1d, size_t siz);
void			free_2d_array(void **array, size_t n);
t_coord			find_chr_in_map(t_map *map, char c);
void			replace_newline_with_null(char *s);
void			destroy_textures(t_game * game);
void			free_all_memory(t_game *game);
void			print_error(char *s);
bool			is_same_coord(t_coord c1, t_coord c2);
void			initialize_player_coord(t_game *game);
void			initialize_enemy_coord(t_game *game);

#endif
