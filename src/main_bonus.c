/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:24:24 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/24 20:25:53 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
__attribute__((destructor)) static void destructor()
{
	system("leaks -q so_long");
}
*/

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (0);
	ft_bzero(&game, sizeof(t_game));
	if (!parse_map(&game, argv[1]))
		return (0);
	game.vars.mlx = mlx_init();
	game.vars.win = mlx_new_window(game.vars.mlx, game.map.column * BLOCK_SIZE,
			(game.map.row + 1) * BLOCK_SIZE, "./so_long");
	if (!load_textures(&game))
	{
		ft_printf("Failed in loading textures\n");
		return (0);
	}
	mlx_hook(game.vars.win, ON_KEYDOWN, 1L << 0, event_handler, &game);
	mlx_hook(game.vars.win, ON_DESTROY, 1L << 17, my_close, &game);
	mlx_loop_hook(game.vars.mlx, update_per_frame, &game);
	mlx_loop(game.vars.mlx);
	return (0);
}
