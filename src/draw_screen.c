/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:34:42 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/24 16:55:21 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_texture_to_window(t_vars *vars, void *img, t_coord coord)
{
	if (coord.y < 0 || coord.x < 0)
		return ;
	mlx_put_image_to_window(vars->mlx, vars->win, img, coord.x * BLOCK_SIZE,
		coord.y * BLOCK_SIZE);
}

void	put_object(t_game *game)
{
	size_t	row_idx;
	size_t	column_idx;

	put_texture_to_window(&game->vars, game->textures.containers[IDX_EXIT],
		find_chr_in_map(&game->map, EXIT));
	row_idx = 0;
	while (row_idx < game->map.row)
	{
		column_idx = 0;
		while (column_idx < game->map.column)
		{
			if (game->map.grid[row_idx][column_idx] == COLLECTIBLE)
				put_texture_to_window(&game->vars,
					game->textures.containers[IDX_COLLECTIBLE],
					(t_coord){row_idx, column_idx});
			column_idx++;
		}
		row_idx++;
	}
}

static bool	is_empty_or_wall(t_game *game, t_coord coord)
{
	return ((game->map.grid[coord.y][coord.x] == EMPTY
		|| game->map.grid[coord.y][coord.x] == WALL)
		&& !(is_same_coord(coord, game->player)) && !(is_same_coord(coord,
				game->enemy)));
}

static void		put_map_helper(t_game *game, size_t row_idx, size_t column_idx)
{
	if (game->map.grid[row_idx][column_idx] == WALL)
		put_texture_to_window(&game->vars, game->textures.containers[IDX_WALL],
			(t_coord){row_idx, column_idx});
	else
		put_texture_to_window(&game->vars, game->textures.containers[IDX_EMPTY],
			(t_coord){row_idx, column_idx});
}

void	put_map(t_game *game)
{
	size_t	row_idx;
	size_t	column_idx;

	row_idx = 0;
	while (row_idx < game->map.row)
	{
		column_idx = 0;
		while (column_idx < game->map.column)
		{
			if (!is_empty_or_wall(game, (t_coord){row_idx, column_idx}))
			{
				column_idx++;
				continue ;
			}
			put_map_helper(game, row_idx, column_idx);
			column_idx++;
		}
		row_idx++;
	}
}
