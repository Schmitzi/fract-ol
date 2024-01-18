/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:17:17 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/12 14:33:24 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_point *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->zx = 0;
	fractal->zy = 0;
	fractal->colour = 0xFCBE11;
	fractal->zoom = 200;
	fractal->endian = 0;
	fractal->x_off = -2.2;
	fractal->y_off = -1.6;
	fractal->iter = 100;
	fractal->custom = 0;
}

void	init_mlx(t_point *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
	{
		free(fractal->mlx);
		free(fractal);
		exit(1);
	}
	fractal->win = mlx_new_window(fractal->mlx, SIZE, SIZE,
			"Fract-ol  |  mgeiger-");
	fractal->img = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->ptr = mlx_get_data_addr(fractal->img, &fractal->bits,
			&fractal->size, &fractal->endian);
	if (!fractal->mlx || !fractal->win || !fractal->ptr)
		close_win(fractal);
}
