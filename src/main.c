/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:18:43 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/19 16:05:49 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	get_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

int	main(void)
{
	t_vars	vars;
	// t_textures	*textures;
	t_map	*map;

	map = parse_map("./maps/map.ber");
	if (!map)
	{
		ft_printf("map allocation failed\n");
		return (0);
	}
	ft_printf("%d\n", map->column);
	ft_printf("%d\n", map->row);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	// textures = load_textures(&vars);
	// (void)textures;
	mlx_loop(vars.mlx);
	return (0);
}
