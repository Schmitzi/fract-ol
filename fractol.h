/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:16:42 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/12 14:36:34 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// SETS
# define JULIA 2
# define MANDEL 3

// KEY CONTROLS
# define ESC 	0xff1b
# define UP 	0xff52
# define DOWN 	0xff54
# define LEFT 	0xff51
# define RIGHT 	0xff53
# define P		0x0070
# define O		0x006f

// MOUSE CONTROLS
# define S_UP 4
# define S_DOWN 5

// OTHER
# define SIZE	800

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

typedef struct s_point
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*ptr;
	int		bits;
	int		size;
	int		endian;
	int		colour;
	int		iter;
	double	x;
	double	cx;
	double	x_off;
	double	zx;
	double	y;
	double	cy;
	double	y_off;
	double	zy;
	double	zoom;
	char	*name;
	int		custom;
}	t_point;

// INITITALIZE
void	init_fractal(t_point *fractal);
void	init_mlx(t_point *fractal);
void	julia_param(t_point *fractal, char *param1, char *param2);

// WINDOW UTILS
int		close_win(t_point *fractal);

// ERROR HANDLING
int		error_free(t_point *fractal);
int		error_param(void);
void	name_check(t_point *fractal, char **argv);

// CONTROLS
int		controls(int key, t_point *fractal);
int		mouse(int input, int x, int y, t_point *fractal);
void	zoom(t_point *fractal, int x, int y, int zoom);

// DRAWING
void	colour_in(t_point *fractal, int x, int y, int colour);
int		draw(t_point *fractal);
void	draw_julia(t_point *fractal);
void	draw_mandelbrot(t_point *fractal);
void	render(t_point *fractal);

// LIBFT
double	ft_atof(const char *str);
char	*ft_strdup(char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(const char *s);

#endif
