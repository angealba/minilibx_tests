/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:41:03 by analbarr          #+#    #+#             */
/*   Updated: 2023/03/31 14:14:10 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_circle(t_data img, int x0, int y0, int radius)
{
	int x;
	int y;
	int err;

	x = radius;
	y = 0;
	err = 0;
	while (x >= y) {
		my_mlx_pixel_put(&img, x0 + x, y0 + y, 0xCC0066);
		my_mlx_pixel_put(&img, x0 + y, y0 + x, 0xCC0066);
		my_mlx_pixel_put(&img, x0 - y, y0 + x, 0xCC0066);
		my_mlx_pixel_put(&img, x0 - x, y0 + y, 0xCC0066);
		my_mlx_pixel_put(&img, x0 - x, y0 - y, 0xCC0066);
		my_mlx_pixel_put(&img, x0 - y, y0 - x, 0xCC0066);
		my_mlx_pixel_put(&img, x0 + y, y0 - x, 0xCC0066);
		my_mlx_pixel_put(&img, x0 + x, y0 - y, 0xCC0066);
		if (err <= 0) 
		{
            y += 1;
            err += 2*y + 1;
        }
		if (err > 0)
		{
            x -= 1;
            err -= 2*x + 1;
        }
	}
}

int	main(void)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;
	int		x0;
	int		y0;
	int		radius;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
			&img.line_lenght, &img.endian);
	x0 = 960;
	y0 = 540;
	radius = 75;
	draw_circle(img, x0, y0, radius);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}