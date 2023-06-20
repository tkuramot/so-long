/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:18:43 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/20 19:51:02 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	game;
	t_textures	*textures;

	game.map = parse_map("./maps/map.ber");
	if (!game.map)
	{
		ft_printf("Error\n");
		return (0);
	}
	initilizePlayerCoord(&game);
	game.vars.mlx = mlx_init();
	game.vars.win = mlx_new_window(game.vars.mlx,
		game.map->column * BLOCK_SIZE, game.map->row * BLOCK_SIZE, "./so_long");
	textures = load_textures(&game.vars);
	draw_all(&game, textures);
	mlx_hook(game.vars.win, ON_KEYDOWN, 1L << 0, event_handler, &game);
	mlx_hook(game.vars.win, ON_DESTROY, 1L << 17, my_close, &game.vars);
	mlx_loop(game.vars.mlx);
	return (0);
}
