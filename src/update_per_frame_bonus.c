/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_per_frame_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:23:45 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/24 02:52:45 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

static void	move_enemy(t_game *game)
{
	static size_t frame;
	int d;
	const int dy[] = {-1, 0, 1, 0};
	const int dx[] = {0, 1, 0, -1};

	if (game->enemy.y == -1 && game->enemy.x == -1)
		return ;
	d = rand() % 4;
	if (frame > 200 && game->map.grid[game->enemy.y + dy[d]]
		[game->enemy.x + dx[d]] == EMPTY)
	{
		game->enemy.y += dy[d];
		game->enemy.x += dx[d];
		frame = 0;
	}
	if (is_same_coord(game->enemy, game->player))
		my_close(game);
	frame++;
}

int	update_per_frame(t_game *game)
{
	put_map(game);
	put_object(game);
	put_sprite_with_animation(game);
	move_enemy(game);
	return (0);
}

