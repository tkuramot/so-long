/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:00:30 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/16 15:48:44 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>

# define EMPTY_TEXTURE e
# define WALL_TEXTURE w
# define COLLECTIBLE_TEXTURE c
# define EXIT_TEXTURE e
# define PLAYER_TEXTURE p

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
	t_list	*grid;
	int		rows;
	int		columns;
}				t_map;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

t_map		*parse_map(char *map_file);
bool		is_valid_map(t_map *map);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
bool		is_surrounded_by_walls(t_map *map);
bool		is_playable(t_map *map);

#endif