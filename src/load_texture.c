/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:29:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/24 15:55:08 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// If a texture was not successfully loaded, free all images already allocated
static bool	load_texture(t_game *game, t_idx_texture idx, char *texture_path)
{
	int	width;
	int	height;

	game->textures.containers[idx] = mlx_xpm_file_to_image(game->vars.mlx,
		texture_path, &width, &height);
	if (!game->textures.containers[idx])
	{
		destroy_textures(game);
		return (false);
	}
	game->textures.counter++;
	return (true);
}

static bool	load_player_texture(t_game *game)
{
	load_texture(game, IDX_PLAYER1, PLAYER1_PATH);
	if (!game->textures.containers[IDX_PLAYER1])
		return (false);
	load_texture(game, IDX_PLAYER2, PLAYER2_PATH);
	if (!game->textures.containers[IDX_PLAYER2])
		return (false);
	return (true);
}

static bool	load_enemy_texture(t_game *game)
{
	load_texture(game, IDX_ENEMY1, ENEMY1_PATH);
	if (!game->textures.containers[IDX_ENEMY1])
		return (false);
	load_texture(game, IDX_ENEMY2, ENEMY2_PATH);
	if (!game->textures.containers[IDX_ENEMY2])
		return (false);
	load_texture(game, IDX_ENEMY3, ENEMY3_PATH);
	if (!game->textures.containers[IDX_ENEMY3])
		return (false);
	load_texture(game, IDX_ENEMY4, ENEMY4_PATH);
	if (!game->textures.containers[IDX_ENEMY4])
		return (false);
	return (true);
}

static bool	load_number_texture(t_game *game)
{
	char	*path;
	size_t	nbr;

	path = ft_strdup(NUMBER_PATH);
	nbr = 0;
	while (nbr < 10)
	{
		path[26] = '0' + nbr;
		load_texture(game, IDX_NUMBER + nbr, path);
		if (!game->textures.containers[IDX_NUMBER + nbr])
		{
			free(path);
			return (false);
		}
		nbr++;
	}
	free(path);
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
	if (!load_player_texture(game))
		return (false);
	if (!load_enemy_texture(game))
		return (false);
	if (!load_number_texture(game))
		return (false);
	return (true);
}
