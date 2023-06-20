/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:24:05 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/20 23:50:44 by tkuramot         ###   ########.fr       */
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
	grid[row_idx] = row;
	return (grid);
}

void	initilizePlayerCoord(t_game *game)
{
	t_coord	player;

	player = find_chr_in_map(game->map, PLAYER);
	game->map->grid[player.y][player.x] = EMPTY;
	game->player.x = player.x;
	game->player.y = player.y;
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

t_map	*parse_map(char *map_file)
{
	int		fd;
	t_map	*map;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = (t_map *)ft_calloc(1, sizeof (t_map));
	if (!map)
		return (NULL);
	map->grid = read_file(fd, 0);
	if (!map->grid)
		return (NULL);
	if (!is_valid_map(map))
		return (NULL);
	return (map);
}
