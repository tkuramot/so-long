/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:51:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/22 10:10:35 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	dfs(t_map *map, bool **seen, t_coord v)
{
	size_t		d;
	t_coord		nv;
	const int	dy[4] = {-1, 0, 1, 0};
	const int	dx[4] = {0, 1, 0, -1};

	seen[v.y][v.x] = true;
	d = 0;
	while (d < 4)
	{
		nv.x = v.x + dx[d];
		nv.y = v.y + dy[d];
		if (nv.x < 0 || nv.x >= (long long)map->column
			|| nv.y < 0 || nv.y >= (long long)map->row
			|| map->grid[nv.y][nv.x] == WALL || seen[nv.y][nv.x])
		{
			d++;
			continue ;
		}
		dfs(map, seen, (t_coord){nv.y, nv.x});
		d++;
	}
}

static bool	is_reachable(char start, char end, t_map *map)
{
	bool	**seen;
	bool	result;
	t_coord	end_coord;

	seen = (bool **)calloc_2d_array(map->row, map->column, sizeof (bool));
	if (!seen)
		return (false);
	dfs(map, seen, find_chr_in_map(map, start));
	end_coord = find_chr_in_map(map, end);
	result = seen[end_coord.y][end_coord.x];
	free_2d_array((void **)seen, map->row);
	return (result);
}

// Check whether the goal is reachable and
// the collectible is collectible
bool	is_playable(t_map *map)
{
	return (is_reachable(PLAYER, EXIT, map)
		&& is_reachable(PLAYER, COLLECTIBLE, map));
}
