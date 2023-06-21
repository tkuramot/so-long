/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:04:56 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/21 20:31:05 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_in_clean_way(t_game *game)
{
	free_2d_array((void **)game->map->grid, game->map->row);
	free(game->map);
	mlx_destroy_image(game->vars.mlx, game->textures.collectible);
	mlx_destroy_image(game->vars.mlx, game->textures.empty);
	mlx_destroy_image(game->vars.mlx, game->textures.wall);
	mlx_destroy_image(game->vars.mlx, game->textures.player);
	mlx_destroy_image(game->vars.mlx, game->textures.exit);
	mlx_destroy_display(game->vars.mlx);
}
