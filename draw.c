/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:18:19 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/12 14:32:25 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw(t_point *fractal)
{
	if (fractal == NULL)
	{
		write(2, "Error: Fractal == NULL\n", 23);
		return (1);
	}
	if (ft_strcmp(fractal->name, "julia") == 0
		|| ft_strcmp(fractal->name, "mandelbrot") == 0)
		render(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	return (0);
}

void	render(t_point *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			if (ft_strcmp(fractal->name, "julia") == 0)
			{
				if (!fractal->custom)
				{
					fractal->cx = -0.76245;
					fractal->cy = 0.06;
				}
				draw_julia(fractal);
			}
			else if (ft_strcmp(fractal->name, "mandelbrot") == 0)
				draw_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}

void	draw_julia(t_point *fractal)
{
	int		i;
	double	temp;

	i = 0;
	fractal->zx = fractal->x / fractal->zoom + fractal->x_off / 1.1;
	fractal->zy = fractal->y / fractal->zoom + fractal->y_off / 0.9;
	while (++i < fractal->iter)
	{
		temp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * temp + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->iter)
		colour_in(fractal, fractal->x, fractal->y, 0xFCBE11);
	else
		colour_in(fractal, fractal->x, fractal->y,
			(fractal->colour * (i % 255)));
}

void	draw_mandelbrot(t_point *fractal)
{
	int		i;
	double	temp;

	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->x_off * 1.1;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->y_off * 1.2;
	while (i < fractal->iter)
	{
		temp = fractal->zx * fractal->zx - fractal->zy
			* fractal->zy + fractal->cx;
		fractal->zy = 2 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = temp;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
		i++;
	}
	if (i == fractal->iter)
		colour_in(fractal, fractal->x, fractal->y, 0xFCBE11);
	else
		colour_in(fractal, fractal->x, fractal->y, (fractal->colour * i));
}

void	colour_in(t_point *fractal, int x, int y, int colour)
{
	int	*buffer;

	buffer = fractal->ptr;
	buffer[(y * fractal->size / 4) + x] = colour;
}
