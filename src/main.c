/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:18:43 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/19 17:32:25 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_vars	vars;
	t_textures	*textures;
	t_map	*map;

	map = parse_map("./maps/map.ber");
	if (!map)
	{
		ft_printf("Error\n");
		return (0);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, map->column * BLOCK_SIZE, map->row * BLOCK_SIZE, "./so_long");
	textures = load_textures(&vars);
	put_map_to_window(&vars, textures, map);
	mlx_loop(vars.mlx);
	return (0);
}
