/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:26:42 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/24 17:26:43 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_surrounded_by_walls(t_map *map)
{
	size_t	row_idx;
	size_t	column_idx;

	column_idx = 0;
	while (column_idx < map->column)
	{
		if (map->grid[0][column_idx] != WALL || map->grid[map->row
			- 1][column_idx] != WALL)
			return (false);
		column_idx++;
	}
	row_idx = 0;
	while (row_idx < map->row)
	{
		if ((map->grid[row_idx][0] != WALL) || (map->grid[row_idx][map->column
				- 1] != WALL))
			return (false);
		row_idx++;
	}
	return (true);
}

// Check whether only valid chars are included and
// EXIT, COLLECTIBLE and PLAYER is solely included
static bool	is_valid_charset(unsigned char *charset)
{
	size_t	c;

	c = 0;
	while (c < UCHAR_MAX + 1)
	{
		if (!ft_strchr("01CEP", c) && charset[c] > 0)
			return (false);
		c++;
	}
	return ((charset[EXIT] == 1) && (charset[COLLECTIBLE] >= 1)
		&& (charset[PLAYER] == 1));
}

// Check whether the map has all chars and doesn't include invalid ones
static bool	has_valid_chars(t_map *map)
{
	unsigned char	charset[UCHAR_MAX + 1];
	size_t			row_idx;
	size_t			column_idx;

	ft_bzero(charset, sizeof(unsigned char) * (UCHAR_MAX + 1));
	row_idx = 0;
	while (row_idx < map->row)
	{
		column_idx = 0;
		while (column_idx < map->column)
		{
			charset[(size_t)map->grid[row_idx][column_idx]]++;
			column_idx++;
		}
		row_idx++;
	}
	return (is_valid_charset(charset));
}

// Check whether the grid is rectangle and update row and column member in map
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
	map->row = row;
	map->column = column;
	return (true);
}

bool	is_valid_map(t_map *map)
{
	if (!has_valid_rows_and_columns(map))
	{
		free_2d_array((void **)map->grid, map->row);
		print_error("The map must be rectangular");
		return (false);
	}
	if (!has_valid_chars(map))
	{
		free_2d_array((void **)map->grid, map->row);
		print_error("The map must contain valid characters");
		return (false);
	}
	if (!is_surrounded_by_walls(map))
	{
		free_2d_array((void **)map->grid, map->row);
		print_error("The map must be surrounded by walls");
		return (false);
	}
	if (!is_playable(map))
	{
		free_2d_array((void **)map->grid, map->row);
		print_error("The map must be playable");
		return (false);
	}
	return (true);
}
