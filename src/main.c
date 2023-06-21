/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:18:43 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/21 23:38:07 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q so_long");
// }

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof (t_game));
	if (!parse_map(&game, argv[argc - 1]))
	{
		ft_printf("Error\n");
		return (0);
	}
	initilizePlayerCoord(&game);
	game.vars.mlx = mlx_init();
	game.vars.win = mlx_new_window(game.vars.mlx,
		game.map.column * BLOCK_SIZE, game.map.row * BLOCK_SIZE, "./so_long");
	if (!load_textures(&game))
	{
		ft_printf("Failed to load textures\n");
		destroy_textures(&game);
		return (0);
	}
	mlx_hook(game.vars.win, ON_KEYDOWN, 1L << 0, event_handler, &game);
	mlx_hook(game.vars.win, ON_DESTROY, 1L << 17, my_close, &game);
	mlx_loop_hook(game.vars.mlx, draw_all, &game);
	mlx_loop(game.vars.mlx);
	return (0);
}
