/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:51:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/20 01:30:36 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	dfs(t_map *map, bool **seen, t_point v)
{
	size_t	d;
	size_t	nx;
	size_t	ny;

	const int dy[4] = {-1, 0, 1, 0};
	const int dx[4] = {0, 1, 0, -1};
	seen[v.y][v.x] = true;
	ft_printf("%d, %d\n", v.x, v.y);
	d = 0;
	while (d < 4)
	{
		nx = v.x + dx[d];
		ny = v.y + dy[d];
		if (0 < nx || nx >= map->column || 0 < ny || ny >= map->row
			|| map->grid[ny][nx] == WALL || seen[ny][nx])
		{
			d++;
			continue;
		}
		dfs(map, seen, get_point(nx, ny));
		d++;
	}
}

static bool	is_reachable(char start, char end, t_map *map)
{
	bool	**seen;
	bool	result;
	t_point	end_point;

	seen = (bool **)calloc_2d_array(map->row, map->column, sizeof (bool));
	if (!seen)
		return (false);
	dfs(map, seen, find_chr_in_map(map, start));
	end_point = find_chr_in_map(map, end);
	result = seen[end_point.y][end_point.x];
	free_2d_array((void **)seen, map->row);
	return (result);
}

// Check whether the goal is reachable and
// the collectible is collectible
bool	is_playable(t_map *map)
{
	ft_printf("==============%d\n", is_reachable(PLAYER, EXIT, map));
	ft_printf("==============%d\n", is_reachable(PLAYER, COLLECTIBLE, map));
	return (is_reachable(PLAYER, EXIT, map)
		&& is_reachable(PLAYER, COLLECTIBLE, map));
}
