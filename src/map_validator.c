/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:56:45 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/16 13:53:14 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check whether the map has all available chars
// and does not include invalid ones;
static bool	has_valid_chars(t_map *map)
{
	size_t	index;
	t_list	*node;
	int		all_chars;

	node = *(map->grid);
	all_chars = 0;
	while (node)
	{
		index = 0;
		while (index < ft_strlen_s(node->content))
			update_chars(((char *)(node->content))[index++], &all_chars);
		node = node->next;
	}
	return (!(all_chars ^ 0b011111));
}

static void	update_chars(char c, int *all_chars)
{
	if (c == EMPTY)
		*all_chars |= EMPTY_BIT;
	else if (c == WALL)
		*all_chars |= WALL_BIT;
	else if (c == COLLECTIBLE)
		*all_chars |= COLLECTIBLE_BIT;
	else if (c == EXIT)
		*all_chars |= EXIT_BIT;
	else if (c == PLAYER)
		*all_chars |= PLAYER_BIT;
	else
		*all_chars |= OTHER_BIT;
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
