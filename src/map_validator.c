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

// Check whether only valid chars are included and
// EXIT, COLLECTIBLE and PLAYER is solely included
static bool	has_valid_chars_helper(unsigned char *all_chars)
{
	size_t	c;

	c = 0;
	while (c < UCHAR_MAX + 1)
	{
		if (!ft_strchr("01CEP", c) && all_chars[c] > 0)
			return (false);
		c++;
	}
	return ((all_chars[EXIT] == 1)
		&& (all_chars[COLLECTIBLE] == 1)
		&& (all_chars[PLAYER] == 1));
}

// Check whether the map has all available chars
// and does not include invalid ones;
static bool	has_valid_chars(t_map *map)
{
	unsigned char	all_chars[UCHAR_MAX];
	t_list			*node;
	char			*s;

	ft_bzero(all_chars, sizeof (unsigned char) * (UCHAR_MAX + 1));
	node = map->grid;
	while (node)
	{
		s = (char *)(node->content);
		while (*s)
			all_chars[(size_t)(*(s++))] += 1;
		node = node->next;
	}
	return (has_valid_chars_helper(all_chars));
}

// Check whether the grid is rectangle
// If it is, update map->rows and map->columns
static bool	has_valid_rows_and_columns(t_map *map)
{
	t_list	*node;
	size_t	columns;
	size_t	rows;

	node = map->grid;
	columns = ft_strlen_s((char *)node->content);
	rows = 1;
	while (node)
	{
		if (columns != ft_strlen_s((char *)node->content))
			return (false);
		rows++;
		node = node->next;
	}
	map->columns = columns;
	map->rows = rows;
	return (true);
}

bool	is_valid_map(t_map *map)
{
	return (has_valid_rows_and_columns(map)
		&& has_valid_chars(map)
		&& is_surrounded_by_walls(map)
		&& is_playable(map));
}
