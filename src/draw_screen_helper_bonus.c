/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen_helper_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:09:12 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/24 01:09:39 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_enemy_with_animation(t_game *game)
{
	static size_t	frame;
	static size_t	cur_frame;
	if (frame > 55)
	{
		cur_frame = (cur_frame + 1) % ENEMY_FRAME;
		frame = 0;
	}
	put_texture_to_window(&game->vars,
		game->textures.containers[IDX_ENEMY1 + cur_frame], game->enemy);
	frame++;
}

void	put_player_with_animation(t_game *game)
{
	static size_t	frame;
	static size_t	cur_frame;
	if (frame > 15)
	{
		cur_frame = (cur_frame + 1) % PLAYER_FRAME;
		frame = 0;
	}
	put_texture_to_window(&game->vars,
		game->textures.containers[IDX_PLAYER1 + cur_frame], game->player);
	frame++;
}

void	put_sprite_with_animation(t_game *game)
{
	put_player_with_animation(game);
	put_enemy_with_animation(game);
}
