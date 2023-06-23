/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:24:05 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/23 23:06:58 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Read map line by line till the eof
static char	**read_file(int fd, size_t row_idx)
{
	char	**grid;
	char	*row;

	row = get_next_line(fd);
	if (!row)
		return ((char **)ft_calloc(row_idx + 1, sizeof (char *)));
	grid = read_file(fd, row_idx + 1);
	if (!grid)
	{
		free(row);
		return (NULL);
	}
	replace_newline_with_null(row);
	grid[row_idx] = row;
	return (grid);
}

t_coord	find_chr_in_map(t_map *map, char c)
{
	size_t	row_idx;
	size_t	column_idx;

	row_idx = 0;
	while (row_idx < map->row)
	{
		column_idx = 0;
		while (column_idx < map->column)
		{
			if (map->grid[row_idx][column_idx] == c)
				return ((t_coord){row_idx, column_idx});
			column_idx++;
		}
		row_idx++;
	}
	return ((t_coord){-1, -1});
}

bool	parse_map(t_game *game, char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		print_error(NULL);
		return (NULL);
	}
	game->map.grid = read_file(fd, 0);
	if (!game->map.grid)
		return (false);
	if (!is_valid_map(&game->map))
		return (false);
	initialize_player_coord(game);
	initialize_enemy_coord(game);
	return (true);
}
