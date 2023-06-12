/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:18:43 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/12 17:14:21 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_point {
	int	x;
	int	y;
}				t_point;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_horizontal_line(t_data *img, t_point point, int color, int len)
{
	for(int i = 0; i < len; i++)
	{
		my_mlx_pixel_put(img, point.x + i, point.y, color);
	}
}

void	print_vertical_line(t_data *img, t_point point, int color, int len)
{
	for(int i = 0; i < len; i++)
	{
		my_mlx_pixel_put(img, point.x, point.y + i, color);
	}
}

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
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	print_horizontal_line(&img, get_point(5, 5), 0x00FF0000, 40);
	print_horizontal_line(&img, get_point(5, 45), 0x00FF0000, 40);
	print_vertical_line(&img, get_point(5, 5), 0x00FF0000, 40);
	print_vertical_line(&img, get_point(45, 5), 0x00FF0000, 40);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
