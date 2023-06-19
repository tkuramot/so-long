/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:51:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/19 18:27:39 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_reachable(char start, char end, t_map *map)
{
	bool	**seen;
	bool	result;
	size_t	row_idx;
	size_t	column_idx;

	row_idx = 0;
	seen = calloc_2d_array(map->row, map->column, sizeof (bool));
	dfs();
	free_2d_array(seen, row_idx);
	return (result);
}

// Check whether the goal is reachable and
// the collectible is collectible
bool	is_playable(t_map *map)
{
	(void)map;
	return (true);
}
