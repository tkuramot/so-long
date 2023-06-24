/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_per_frame_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:23:45 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/24 17:33:09 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

static void	move_enemy(t_game *game)
{
	static size_t	frame;
	int				d;
	const int	dy[] = {-1, 0, 1, 0};
	const int	dx[] = {0, 1, 0, -1};

	if (game->enemy.y == -1 && game->enemy.x == -1)
		return ;
	d = rand() % 4;
	if (frame > 300 && game->map.grid[game->enemy.y + dy[d]][game->enemy.x
		+ dx[d]] == EMPTY)
	{
		game->enemy.y += dy[d];
		game->enemy.x += dx[d];
		frame = 0;
	}
	if (is_same_coord(game->enemy, game->player))
		my_close(game);
	frame++;
}

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

static void	print_move_helper(t_game *game, long long nbr, t_coord coord)
{
	if (nbr >= 10)
	{
		print_move_helper(game, nbr / 10, (t_coord){coord.y, coord.x - 1});
	}
	put_texture_to_window(&game->vars, game->textures.containers[IDX_NUMBER
		+ nbr % 10], coord);
}

static void	print_move(t_game *game)
{
	t_coord	offset;

	offset.y = game->map.row;
	offset.x = game->map.column - 1;
	print_move_helper(game, game->move, offset);
}

int	update_per_frame(t_game *game)
{
	put_map(game);
	put_object(game);
	put_sprite_with_animation(game);
	move_enemy(game);
	print_move(game);
	return (0);
}
