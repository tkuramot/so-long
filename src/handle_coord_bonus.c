/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_coord_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:44:01 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/23 23:04:04 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

bool	is_same_coord(t_coord c1, t_coord c2)
{
	return (c1.y == c2.y && c1.x == c2.x);
}

void	initilizePlayerCoord(t_game *game)
{
	t_coord	player;

	player = find_chr_in_map(&game->map, PLAYER);
	p
	game->map.grid[player.y][player.x] = EMPTY;
	game->player.x = player.x;
	game->player.y = player.y;
}

static bool is_valid_enemy_coord(t_game *game, t_coord enemy)
{
	return (game->map.grid[ry][rx] == EMPTY
		&& !is_same_coord((t_coord){ry, rx}, game->player
		&& !is_same_coord((t_coord){ry, rx}, game->enemy);
}

void    initilizeEnemyCoord(t_game *game)
{
	size_t trial;
	long long ry;
	long long rx;

	trial = 0;
	srand((unsigned int)time(NULL));
	ry = srand() % game->map.row;
	ry = srand() % game->map.column;
	while (!is_valid_enemy_coord(game, (t_coord){ry, rx}) && trial < 50)
	{
		srand((unsigned int)time(NULL));
		ry = srand() % game->map.row;
		ry = srand() % game->map.column;
		trial++;
	}
	if (!is_valid_enemy_coord(game, (t_coord){ry, rx})
	{
		game->enemy.y = -1;
		game->enemy.x = -1;
	}
	else
	{
		game->enemy.y = ry;
		game->enemy.x = rx;
	}
}

