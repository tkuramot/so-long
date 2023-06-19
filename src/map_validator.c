/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:56:45 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/16 13:50:54tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_surrounded_by_walls(t_map *map)
{
	size_t	row_idx;
	size_t	column_idx;

	row_idx = 0;
	column_idx = 0;
	while (column_idx < map->column)
	{
		if (map->grid[0][column_idx] != WALL
			|| map->grid[map->row - 1][column_idx] != WALL)
			return (false);
		column_idx++;
	}
	while (row_idx < map->row)
	{
		if ((map->grid[row_idx][0] != WALL)
			|| (map->grid[row_idx][map->column - 1] != WALL))
			return (false);
		row_idx++;
	}
	return (true);
}

// Check whether only valid chars are included and
// EXIT, COLLECTIBLE and PLAYER is solely included
static bool	has_valid_chars_helper(unsigned char *charset)
{
	size_t	c;

	c = 0;
	while (c < UCHAR_MAX + 1)
	{
		if (!ft_strchr("01CEP", c) && charset[c] > 0)
			return (false);
		c++;
	}
	return ((charset[EXIT] == 1)
		&& (charset[COLLECTIBLE] == 1)
		&& (charset[PLAYER] == 1));
}

// Check whether the map has all chars and doesn't include invalid ones
static bool	has_valid_chars(t_map *map)
{
	unsigned char	charset[UCHAR_MAX + 1];
	size_t			row_idx;
	size_t			column_idx;

	ft_bzero(charset, sizeof (unsigned char) * (UCHAR_MAX + 1));
	row_idx = 0;
	while (row_idx < map->row)
	{
		ft_printf("%s", map->grid[row_idx]);
		column_idx = 0;
		while (column_idx < map->column)
		{
			charset[(size_t)map->grid[row_idx][column_idx]]++;
			column_idx++;
		}
		row_idx++;
	}
	return (has_valid_chars_helper(charset));
}

// Check whether the grid is rectangle and update row and column member in map
// column - 1 for newline, row - 1 for null termination
static bool	has_valid_rows_and_columns(t_map *map)
{
	char	**grid;
	size_t	row;
	size_t	column;

	grid = map->grid;
	row = 0;
	column = ft_strlen_s(grid[row]);
	while (grid[++row])
		if (column != ft_strlen_s(grid[row]))
			return (false);
	map->column = column - 1;
	map->row = row;
	return (true);
}

bool	is_valid_map(t_map *map)
{
	return (has_valid_rows_and_columns(map)
		&& has_valid_chars(map)
		&& is_surrounded_by_walls(map)
		&& is_playable(map));
}
