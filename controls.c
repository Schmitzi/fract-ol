/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:21:02 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/12 14:33:07 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	controls(int key, t_point *fractal)
{
	if (key == ESC)
		close_win(fractal);
	else if (key == LEFT)
		fractal->x_off -= 100 / fractal->zoom;
	else if (key == RIGHT)
		fractal->x_off += 100 / fractal->zoom;
	else if (key == UP)
		fractal->y_off -= 100 / fractal->zoom;
	else if (key == DOWN)
		fractal->y_off += 100 / fractal->zoom;
	else if (key == O)
		fractal->iter -= 75;
	else if (key == P)
		fractal->iter += 75;
	draw(fractal);
	return (0);
}

int	mouse(int input, int x, int y, t_point *fractal)
{
	if (input == S_UP)
		zoom(fractal, x, y, 1);
	else if (input == S_DOWN)
		zoom(fractal, x, y, -1);
	draw(fractal);
	return (0);
}

void	zoom(t_point *fractal, int x, int y, int zoom)
{
	double	level;

	level = 1.42;
	if (zoom == 1)
	{
		fractal->x_off = (x / fractal->zoom + fractal->x_off)
			- (x / (fractal->zoom * level));
		fractal->y_off = (y / fractal->zoom + fractal->y_off)
			- (y / (fractal->zoom * level));
		fractal->zoom *= level;
	}
	else if (zoom == -1)
	{
		fractal->x_off = (x / fractal->zoom + fractal->x_off)
			- (x / (fractal->zoom / level));
		fractal->y_off = (y / fractal->zoom + fractal->y_off)
			- (y / (fractal->zoom / level));
		fractal->zoom /= level;
	}
}
