/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:29:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/22 10:21:45 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// If a texture was not successfully loaded, free all images already allocated
static bool	load_texture(t_game *game, t_idx_texture idx, char *texture_path)
{
	int		width;
	int		height;

	game->textures.containers[idx] =
		mlx_xpm_file_to_image(game->vars.mlx, texture_path, &width, &height);
	if (!game->textures.containers[idx])
	{
		destroy_textures(game);
		return (false);
	}
	game->textures.counter++;
	return (true);
}

bool	load_textures(t_game *game)
{
	load_texture(game, IDX_EMPTY, EMPTY_PATH);
	if (!game->textures.containers[IDX_EMPTY])
		return (false);
	load_texture(game, IDX_WALL, WALL_PATH);
	if (!game->textures.containers[IDX_WALL])
		return (false);
	load_texture(game, IDX_COLLECTIBLE, COLLECTIBLE_PATH);
	if (!game->textures.containers[IDX_COLLECTIBLE])
		return (false);
	load_texture(game, IDX_EXIT, EXIT_PATH);
	if (!game->textures.containers[IDX_EXIT])
		return (false);
	load_texture(game, IDX_PLAYER, PLAYER_PATH);
	if (!game->textures.containers[IDX_PLAYER])
		return (false);
	return (true);
}