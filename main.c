/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:12:38 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/12 11:47:39 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_point	*fractal;

	if (argc == 1 || argc == 3 || (ft_strcmp(argv[1], "julia") != 0 && \
			ft_strcmp(argv[1], "mandelbrot") != 0) || (argc == 4 && \
			(ft_strcmp(argv[1], "mandelbrot") == 0)) || argc > 4)
	{
		error_param();
		exit(1);
	}
	fractal = malloc(sizeof(t_point));
	if (!fractal)
		return (1);
	name_check(fractal, argv);
	init_fractal(fractal);
	if (argc == 4 && argv)
		julia_param(fractal, argv[2], argv[3]);
	init_mlx(fractal);
	mlx_key_hook(fractal->win, controls, fractal);
	mlx_mouse_hook(fractal->win, mouse, fractal);
	mlx_hook(fractal->win, 33, 0L, close_win, fractal);
	draw(fractal);
	mlx_loop(fractal->mlx);
	close_win(fractal);
	free(fractal);
	return (0);
}
