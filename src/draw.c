/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:34:42 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/22 22:46:59 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_texture_to_window(t_vars *vars, void *img, t_coord coord)
{
	if (coord.y < 0 || coord.x < 0)
		return ;
	mlx_put_image_to_window(vars->mlx, vars->win, img,
		coord.x * BLOCK_SIZE, coord.y * BLOCK_SIZE);
}

static void	put_entity_to_window(t_game *game)
{
	put_texture_to_window(&game->vars, game->textures.containers[IDX_PLAYER1], game->player);
	put_texture_to_window(&game->vars, game->textures.containers[IDX_EXIT],
		find_chr_in_map(&game->map, EXIT));
	put_texture_to_window(&game->vars, game->textures.containers[IDX_COLLECTIBLE],
		find_chr_in_map(&game->map, COLLECTIBLE));
}

static bool	is_empty_or_wall(t_game *game, t_coord coord)
{
	return (is_same_coord(coord, game->player)
		|| is_same_coord(coord, find_chr_in_map(&game->map, COLLECTIBLE))
		|| is_same_coord(coord, find_chr_in_map(&game->map, EXIT)));
}

static void	put_map_to_window(t_game *game)
{
	size_t	row_idx;
	size_t	column_idx;

	row_idx = 0;
	while (row_idx < game->map.row)
	{
		column_idx = 0;
		while (column_idx < game->map.column)
		{
			if (is_empty_or_wall(game, (t_coord){row_idx, column_idx}))
			{
				column_idx++;
				continue;
			}
			if (game->map.grid[row_idx][column_idx] == WALL)
				put_texture_to_window(&game->vars, game->textures.containers[IDX_WALL],
					(t_coord){row_idx, column_idx});
			else
				put_texture_to_window(&game->vars, game->textures.containers[IDX_EMPTY],
					(t_coord){row_idx, column_idx});
			column_idx++;
		}
		row_idx++;
	}
}

int	draw_all(t_game *game)
{
	put_map_to_window(game);
	put_entity_to_window(game);
	return (0);
}
