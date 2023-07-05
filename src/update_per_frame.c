/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_per_frame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:19:07 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/24 15:47:17 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(int keycode, t_game *game)
{
	if (keycode == UP)
		resolve_action(game, (t_coord){game->player.y - 1, game->player.x});
	if (keycode == DOWN)
		resolve_action(game, (t_coord){game->player.y + 1, game->player.x});
	if (keycode == LEFT)
		resolve_action(game, (t_coord){game->player.y, game->player.x - 1});
	if (keycode == RIGHT)
		resolve_action(game, (t_coord){game->player.y, game->player.x + 1});
	return (0);
}

int	update_per_frame(t_game *game)
{
	put_map(game);
	put_object(game);
	put_sprite_with_animation(game);
	return (0);
}
