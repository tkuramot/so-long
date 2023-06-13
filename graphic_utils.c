/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:34:42 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/13 14:35:11 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
