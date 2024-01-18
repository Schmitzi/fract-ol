/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:16:18 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/12 11:46:37 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	error_free(t_point *fractal)
{
	free(fractal);
	return (1);
}

int	error_param(void)
{
	write(2, "Usage: ./fractol <set> <julia parameters>\n", 42);
	write(2, "Available sets: julia, mandelbrot\n", 34);
	return (1);
}
