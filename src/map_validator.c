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
static bool	has_valid_chars(unsigned char *all_chars)
{
	bool	ok;
	size_t	c;

	ok = true;
	c = 0;
	while (c < UCHAR_MAX + 1)
	{
		if (!ft_strchr("01CEP", c) && all_chars[c] > 0)
			return (false);
		c++;
	}
	ok &= (all_chars[EXIT] == 1);
	ok &= (all_chars[COLLECTIBLE] == 1);
	ok &= (all_chars[PLAYER] == 1);
	return (ok);
}

// Check whether the map has all available chars
// and does not include invalid ones;
static bool	has_valid_chars(t_map *map)
{
	unsigned char	all_chars[UCHAR_MAX];
	t_list			*node;
	char			*s;

	ft_bzero(all_chars, sizeof (unsigned char) * (UCHAR_MAX + 1));
	node = *(map->grid);
	while (node)
	{
		s = (char *)(node->content);
		while (*s)
			all_chars[*(s++)] += 1;
		node = node->next;
	}
	return (has_valid_chars(all_chars));
}

static bool	is_surrounded_by_walls(t_map *map)
{
}

// Check whether the grid is rectangle
// If it is, update map->rows and map->columns
static bool	has_valid_rows_and_columns(t_map *map)
{
}

bool	is_valid_map(t_map *map)
{
	bool	is_valid;

	is_valid = true;
	is_valid &= has_valid_rows_and_columns(map);
	is_valid &= has_valid_chars(map);
	is_valid &= is_surrounded_by_walls(map);
	is_valid &= is_playable(map);
	return (is_valid);
}
