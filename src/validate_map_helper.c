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

static t_coord	*dup_coord(t_coord v)
{
	t_coord	*nv;

	nv = ft_calloc(1, sizeof (t_coord));
	if (!nv)
		return (false);
	ft_memcpy(nv, &v, sizeof (t_coord));
	return (nv);
}

static void	check_cross(t_map *map, bool **seen, t_list *queue, char *passable)
{
	size_t		d;
	t_coord		nv;
	const int	dy[] = {-1, 0, 1, 0};
	const int	dx[] = {0, 1, 0, -1};

	d = 0;
	while (d < 4)
	{
		nv.x = ((t_coord *)queue->content)->x + dx[d];
		nv.y = ((t_coord *)queue->content)->y + dy[d];
		if (0 <= nv.x && nv.x < (long long)map->column && 0 <= nv.y
			&& nv.y < (long long)map->row && ft_strchr(passable, map->grid[nv.y][nv.x])
			&& !seen[nv.y][nv.x])
		{
			seen[nv.y][nv.x] = true;
			ft_lstadd_back(&queue, ft_lstnew(dup_coord(nv)));
		}
		d++;
	}
}

static void	bfs(t_map *map, bool **seen, t_coord *v, char *passable)
{
	t_list		*queue;
	t_list		*node;

	queue = ft_lstnew(v);
	if (!queue)
		return ;
	seen[v->y][v->x] = true;
	while (queue)
	{
		check_cross(map, seen, queue, passable);
		node = queue;
		queue = queue->next;
		ft_lstdelone(node, free);
	}
}

static bool	is_reachable(t_coord start, t_coord end, char *passable, t_map *map)
{
	bool	**seen;
	bool	result;

	seen = (bool **)calloc_2d_array(map->row, map->column, sizeof(bool));
	if (!seen)
		return (false);
	bfs(map, seen, dup_coord(start), passable);
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

	if (!is_reachable(find_chr_in_map(map, PLAYER), find_chr_in_map(map, EXIT), "0EC", map))
		return (false);
	row_idx = 0;
	while (row_idx < map->row)
	{
		column_idx = 0;
		while (column_idx < map->column)
		{
			if (map->grid[row_idx][column_idx] == COLLECTIBLE)
			{
				if (!is_reachable(find_chr_in_map(map, PLAYER), (t_coord){row_idx, column_idx}, "0C", map))
					return (false);
			}
			column_idx++;
		}
		row_idx++;
	}
	return (true);
}
