/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:18:43 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/14 02:55:58 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	get_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return point;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	// t_data	img;
	void *lava_img;
	char *relative_path = "./Tileset/Original Textures/Lava.png";
	int img_width;
	int img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// print_horizontal_line(&img, get_point(5, 5), 0x00FF0000, 40);
	// print_horizontal_line(&img, get_point(5, 45), 0x00FF0000, 40);
	// print_vertical_line(&img, get_point(5, 5), 0x00FF0000, 40);
	// print_vertical_line(&img, get_point(45, 5), 0x00FF0000, 40);
	mlx_png_file_to_img(lava_img, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, lava_img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
