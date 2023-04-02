/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_testing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:23:45 by analbarr          #+#    #+#             */
/*   Updated: 2023/04/02 16:24:46 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct  s_vars
{
    void    *mlx;
    void    *win;
}   t_vars;

/*It closes the window when pressing any key.*/
int close(int keycode, t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    return (0);
}

int main(void)
{
    t_vars  vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "hello world!");
    mlx_hook(vars.win, 2, 1L<<2, close, &vars);
    mlx_loop(vars.mlx);
}