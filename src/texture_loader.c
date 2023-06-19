/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:29:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/19 17:29:35 by tkuramot         ###   ########.fr       */
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

t_textures	*load_textures(t_vars	*vars)
{
	t_textures	*textures;

	textures = (t_textures *)malloc(sizeof (t_textures));
	if (!textures)
		return (NULL);
	textures->empty = load_texture(vars, EMPTY_PATH);
	textures->wall = load_texture(vars, WALL_PATH);
	textures->collectible = load_texture(vars, COLLECTIBLE_PATH);
	textures->exit = load_texture(vars, EXIT_PATH);
	textures->player = load_texture(vars, PLAYER_PATH);
	if (!textures->empty || !textures->wall || !textures->collectible
		|| !textures->exit || !textures->player)
		return (NULL);
	return (textures);
}