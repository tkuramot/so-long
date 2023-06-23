/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:21:17 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/23 23:09:08 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_same_coord(t_coord c1, t_coord c2)
{
	return (c1.y == c2.y && c1.x == c2.x);
}

void	initializePlayerCoord(t_game *game)
{
	t_coord	player;

	player = find_chr_in_map(&game->map, PLAYER);
	game->map.grid[player.y][player.x] = EMPTY;
	game->player.x = player.x;
	game->player.y = player.y;
}
void    initializeEnemyCoord(t_game *game)
{
	(void)game;
}

