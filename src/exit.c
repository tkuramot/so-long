/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:04:56 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/22 10:06:55 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_textures(t_game *game)
{
	size_t	counter;

	counter = 0;
	while (counter < game->textures.counter)
		mlx_destroy_image(game->vars.mlx, game->textures.containers[counter++]);
}

void	free_all_memory(t_game *game)
{
	free_2d_array((void **)game->map.grid, game->map.row);
	destroy_textures(game);
	exit(0);
}
