/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:12:17 by analbarr          #+#    #+#             */
/*   Updated: 2023/04/01 18:12:51 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct s_img
{
    void    *mlx_img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}   t_img;

typedef struct	s_data{
	void	*mlx_ptr;
	void	*win_ptr;
    t_img   img;
}	t_data;

typedef struct	s_rect
{
	int	x;
	int	y;
	int width;
	int	height;
	int	color;
}	t_rect;

void    img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(int *)pixel = color;
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while(i < rect.y + rect.height)
	{
		j = rect.x;
		while(j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	main(void)
{
	t_img	img;
	t_rect	rectangle;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello world!");
	img.mlx_img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);
	rectangle.x = 300;
	rectangle.y = 150;
	rectangle.width = 300;
	rectangle.height = 150;
	rectangle.color = 0xFF99CC;
	render_rect(&img, rectangle);
	mlx_put_image_to_window(mlx, mlx_win, img.mlx_img, 0, 0);
	mlx_loop(mlx);
}