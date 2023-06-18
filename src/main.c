/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:18:43 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/18 19:23:10 by tkuramot         ###   ########.fr       */
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
	t_textures	*textures;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	// lava_img = mlx_png_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	// ft_printf("%p\n", lava_img);
	textures = load_textures(&vars);
	mlx_loop(vars.mlx);
	// t_map	*map = parse_map("./maps/map.ber");
	// ft_printf("%d\n", map->columns);
	// ft_printf("%d\n", map->rows);
	return (0);
}
