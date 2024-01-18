/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:25:09 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/11 22:25:24 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_point *fractal)
{
	if (fractal->img)
		mlx_destroy_image(fractal->mlx, fractal->img);
	if (fractal->win)
		mlx_destroy_window(fractal->mlx, fractal->win);
	if (fractal->ptr)
		mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (1);
}

void	name_check(t_point *fractal, char **argv)
{
	if (ft_strcmp(argv[1], "julia") == 0)
		fractal->name = "julia";
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		fractal->name = "mandelbrot";
}

void	julia_param(t_point *fractal, char *param1, char *param2)
{
	if (!param1 || !param2)
		close_win(fractal);
	if (ft_strcmp(fractal->name, "julia") == 0)
	{
		fractal->custom = 1;
		fractal->cx = ft_atof(param1);
		fractal->cy = ft_atof(param2);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	if (dest == 0)
		return (0);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
