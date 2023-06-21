/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:29:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/21 23:37:49 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_textures	*load_texture(t_vars *vars, char *texture_path)
{
	void	*texture;
	int		width;
	int		height;

	texture = malloc(sizeof (void *));
	texture = mlx_xpm_file_to_image(vars->mlx, texture_path, &width, &height);
		ft_printf("%p\n", texture);
	return (texture);
}

bool	load_textures(t_game *game)
{
	game->textures.containers[IDX_EMPTY] = load_texture(&game->vars, EMPTY_PATH);
	if (!game->textures.containers[IDX_EMPTY])
		return (false);
	game->textures.counter++;

	game->textures.containers[IDX_WALL] = load_texture(&game->vars, WALL_PATH);
	if (!game->textures.containers[IDX_WALL])
		return (false);
	game->textures.counter++;

	game->textures.containers[IDX_COLLECTIBLE] =
		load_texture(&game->vars, COLLECTIBLE_PATH);
	if (!game->textures.containers[IDX_COLLECTIBLE])
		return (false);
	game->textures.counter++;

	game->textures.containers[IDX_EXIT] = load_texture(&game->vars, EXIT_PATH);
	if (!game->textures.containers[IDX_EXIT])
		return (false);
	game->textures.counter++;

	game->textures.containers[IDX_PLAYER] = load_texture(&game->vars, PLAYER_PATH);
	if (!game->textures.containers[IDX_PLAYER])
		return (false);
	game->textures.counter++;
	return (true);
}