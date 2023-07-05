/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:24:05 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/05 08:28:36 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	count_rows(char *map_file)
{
	int		fd;
	size_t	count;
	char	*row;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		print_error(NULL);
		return (0);
	}
	count = 0;
	while (true)
	{
		row = get_next_line(fd);
		if (!row)
			break ;
		free(row);
		count++;
	}
	close(fd);
	return (count);
}

// Read map line by line till the eof
static char	**read_file(char *map_file, size_t rows)
{
	size_t	idx;
	char	**grid;
	char	*row;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		print_error(NULL);
		return (NULL);
	}
	grid = (char **)ft_calloc(rows + 1, sizeof(char *));
	if (!grid)
		return (NULL);
	idx = 0;
	while (true)
	{
		row = get_next_line(fd);
		if (!row)
			break ;
		replace_newline_with_null(row);
		grid[idx++] = row;
	}
	close(fd);
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
	size_t	rows;

	rows = count_rows(map_file);
	if (!rows)
		return (false);
	game->map.grid = read_file(map_file, rows);
	if (!game->map.grid)
		return (false);
	if (!is_valid_map(&game->map))
		return (false);
	initialize_player_coord(game);
	initialize_enemy_coord(game);
	return (true);
}
