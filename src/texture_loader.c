/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:29:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/20 20:09:30 by tkuramot         ###   ########.fr       */
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
	return (texture);
}

bool	load_textures(t_game *game)
{
	game->textures.empty = load_texture(&game->vars, EMPTY_PATH);
	game->textures.wall = load_texture(&game->vars, WALL_PATH);
	game->textures.collectible = load_texture(&game->vars, COLLECTIBLE_PATH);
	game->textures.exit = load_texture(&game->vars, EXIT_PATH);
	game->textures.player = load_texture(&game->vars, PLAYER_PATH);
	if (!game->textures.empty || !game->textures.wall
		|| !game->textures.collectible || !game->textures.exit
		|| !game->textures.player)
		return (false);
	return (true);
}