/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:34:42 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/18 19:24:33 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

static t_textures	*load_texture(t_vars *vars, char *texture_path)
{
	void	*texture;
	int		width;
	int		height;

	texture = malloc(sizeof (void *));
	texture = mlx_png_file_to_image(vars->mlx, texture_path, &width, &height);
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

void	update_window(t_vars *vars, t_textures *textures, t_map *map)
{
	while ()
	{
		while ()
		{
			mlx_put_image_to_window(vars->mlx, vars->win, textures->wall, 0, 0);
		}
	}
}
