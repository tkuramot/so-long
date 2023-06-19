/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:34:42 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/19 18:18:32 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	put_player_to_window(t_vars *vars, t_textures *textures, t_point point)
// {
// 	mlx_put_image_to_window(vars->mlx, vars->win, textures->player,
// 		point.x, point.y);
// }

void	put_map_to_window(t_vars *vars, t_textures *textures, t_map *map)
{
	size_t	row_idx;
	size_t	column_idx;

	row_idx = 0;
	while (row_idx < map->row)
	{
		column_idx = 0;
		while (column_idx < map->column)
		{
			if (map->grid[row_idx][column_idx] == WALL)
			{
				mlx_put_image_to_window(vars->mlx, vars->win, textures->wall,
					column_idx * BLOCK_SIZE, row_idx * BLOCK_SIZE);
			}
			else
			{
				mlx_put_image_to_window(vars->mlx, vars->win, textures->empty,
					column_idx * BLOCK_SIZE, row_idx * BLOCK_SIZE);
			}
			column_idx++;
		}
		row_idx++;
	}
}
