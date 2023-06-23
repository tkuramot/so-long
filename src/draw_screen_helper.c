/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:53:43 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/23 10:29:59 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_sprite_with_animation(t_game *game)
{
	put_texture_to_window(&game->vars,
		game->textures.containers[IDX_PLAYER1], game->player);
}
