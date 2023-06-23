/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 01:13:22 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/24 01:14:22 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_close(t_game *game)
{
	free_all_memory(game);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	exit(0);
}

static void	resolve_action(t_game *game, t_coord player)
{
	if (game->map.grid[player.y][player.x] == EMPTY
		|| game->map.grid[player.y][player.x] == COLLECTIBLE)
	{
		game->player.y = player.y;
		game->player.x = player.x;
		game->move++;
		ft_printf("Move: %d\n", game->move);
	}
	if (game->map.grid[player.y][player.x] == EXIT
		|| is_same_coord(game->player, game->enemy))
	{
		game->move++;
		ft_printf("Move: %d\n", game->move);
		my_close(game);
	}
	if (game->map.grid[player.y][player.x] == COLLECTIBLE)
		game->map.grid[player.y][player.x] = EMPTY;
}

static int	move_player(int keycode, t_game *game)
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

int	event_handler(int keycode, t_game *game)
{
	if (keycode == ESC)
		my_close(game);
	else
		move_player(keycode, game);
	return (0);
}
