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

typedef struct	s_rect
{
	int	x;
	int	y;
	int width;
	int	height;
	int	color;
}	t_rect;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	render_rect(t_data img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while(i < rect.y + rect.height)
	{
		j = rect.x;
		while(j < rect.x + rect.width)
			my_mlx_pixel_put(&img, j++, i, 0xCC99FF);
		++i;
	}
	return (0);
}

int	main(void)
{
	t_data	img;
	t_rect	rectangle;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
			&img.line_lenght, &img.endian);
	rectangle.x = 300;
	rectangle.y = 150;
	rectangle.width = 300;
	rectangle.height = 150;
	rectangle.color = 0xCC99FF;
	render_rect(img, rectangle);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}