/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:26:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/12 20:37:51by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

static int	move_player(int keycode, t_game *game)
{
	if (keycode == UP)
		game->player_coord.y--;
	if (keycode == DOWN)
		game->player_coord.y++;
	if (keycode == LEFT)
		game->player_coord.x--;
	if (keycode == RIGHT)
		game->player_coord.x++;
	return (0);
}

int	event_handler(int keycode, t_game *game)
{
	if (keycode == ESC)
		my_close(&game->vars);
	else
		move_player(keycode, game);
	return (0);
}
