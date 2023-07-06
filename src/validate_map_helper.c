/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:51:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/24 17:32:50 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	dfs(t_map *map, bool **seen, t_coord v)
{
	size_t		d;
	t_coord		nv;
	const int	dy[] = {-1, 0, 1, 0};
	const int	dx[] = {0, 1, 0, -1};

	seen[v.y][v.x] = true;
	d = 0;
	while (d < 4)
	{
		nv.x = v.x + dx[d];
		nv.y = v.y + dy[d];
		if (nv.x < 0 || nv.x >= (long long)map->column || nv.y < 0
			|| nv.y >= (long long)map->row || map->grid[nv.y][nv.x] == WALL
			|| seen[nv.y][nv.x])
		{
			d++;
			continue ;
		}
		dfs(map, seen, (t_coord){nv.y, nv.x});
		d++;
	}
}

static bool	is_reachable(t_coord start, t_coord end, t_map *map)
{
	bool	**seen;
	bool	result;

	seen = (bool **)calloc_2d_array(map->row, map->column, sizeof(bool));
	if (!seen)
		return (false);
	dfs(map, seen, start);
	result = seen[end.y][end.x];
	free_2d_array((void **)seen, map->row);
	return (result);
}

// Check whether the goal is reachable and
// the collectible is collectible
bool	is_playable(t_map *map)
{
	size_t	row_idx;
	size_t	column_idx;

	if (!is_reachable(find_chr_in_map(map, PLAYER), find_chr_in_map(map, EXIT), map))
		return (false);
	row_idx = 0;
	while (row_idx < map->row)
	{
		column_idx = 0;
		while (column_idx < map->column)
		{
			if (map->grid[row_idx][column_idx] == COLLECTIBLE)
			{
				if (!is_reachable(find_chr_in_map(map, PLAYER), (t_coord){row_idx, column_idx}, map))
					return (false);
			}
			column_idx++;
		}
		row_idx++;
	}
	return (true);
}
