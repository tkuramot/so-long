#ifndef SO_LONG_H
#define SO_LONG_H

#include "libft/include/libft.h"
#include "mlx.h"

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

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	print_horizontal_line(t_data *img, t_point point, int color, int len);
void	print_vertical_line(t_data *img, t_point point, int color, int len);

#endif