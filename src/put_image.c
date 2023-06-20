/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:34:42 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/20 19:47:15 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_texture_to_window(t_vars *vars, void *img, t_coord coord)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img,
		coord.x * BLOCK_SIZE, coord.y * BLOCK_SIZE);
}

static void	put_entity_to_window(t_game *game, t_textures *textures)
{
	put_texture_to_window(&game->vars, textures->player, game->player_coord);
	put_texture_to_window(&game->vars, textures->exit,
		find_chr_in_map(game->map, EXIT));
	put_texture_to_window(&game->vars, textures->collectible,
		find_chr_in_map(game->map, COLLECTIBLE));
}

static void	put_map_to_window(t_game *game, t_textures *textures)
{
	size_t	row_idx;
	size_t	column_idx;

	row_idx = 0;
	while (row_idx < game->map->row)
	{
		column_idx = 0;
		while (column_idx < game->map->column)
		{
			if (game->map->grid[row_idx][column_idx] == WALL)
				put_texture_to_window(&game->vars, textures->wall,
					(t_coord){row_idx, column_idx});
			else
				put_texture_to_window(&game->vars, textures->empty,
					(t_coord){row_idx, column_idx});
			column_idx++;
		}
		row_idx++;
	}
}

void	draw_all(t_game *game, t_textures *textures)
{
	put_map_to_window(game, textures);
	put_entity_to_window(game, textures);
}
