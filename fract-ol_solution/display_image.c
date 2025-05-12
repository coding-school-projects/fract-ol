/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:42:28 by pchennia          #+#    #+#             */
/*   Updated: 2024/04/14 16:41:44 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_to_pixel(t_display *f, int win_x, int win_y, int color)
{
	int	*temp;

	temp = f->img_info_ptr;
	temp[(win_y * f->line_len / 4) + win_x] = color;
}

int	calculate_burning_ship(t_display *f)
{
	int		i;
	double	x_temp;

	i = 0;
	while (++i < f->max_iteration)
	{
		x_temp = f->real * f->real - f->imaginary * f->imaginary
			+ f->complex_x;
		f->imaginary = fabs(2.0 * f->real * f->imaginary) + f->complex_y;
		f->real = fabs(x_temp);
		if (f->real * f->real + f->imaginary
			* f->imaginary >= __DBL_MAX__)
			break ;
	}
	return (i);
}

int	calculate_julia(t_display *f)
{
	int		i;
	double	temp;

	i = 0;
	while (++i < f->max_iteration)
	{
		temp = f->complex_x;
		f->complex_x = f->complex_x * f->complex_x - f->complex_y
			* f->complex_y + f->julia_x;
		f->complex_y = 2 * f->complex_y * temp + f->julia_y;
		if (f->complex_x * f->complex_x + f->complex_y
			* f->complex_y >= __DBL_MAX__)
			break ;
	}
	return (i);
}

int	calculate_mandelbrot(t_display *f)
{
	int		i;
	double	x_temp;

	i = 0;
	while (++i < f->max_iteration)
	{
		x_temp = f->real * f->real - f->imaginary * f->imaginary + f->complex_x;
		f->imaginary = 2. * f->real * f->imaginary + f->complex_y;
		f->real = x_temp;
		if (f->real * f->real + f->imaginary * f->imaginary >= __DBL_MAX__)
			break ;
	}
	return (i);
}

void	calculate_fractal(t_display *f, char *input)
{
	int	no_of_iteration;

	f->real = 0.0;
	f->imaginary = 0.0;
	no_of_iteration = 0;
	f->complex_x = (f->win_x / f->img_size) + f->img_x;
	f->complex_y = (f->win_y / f->img_size) + f->img_y;
	if (ft_strcmp(input, "mandel") == 0)
		no_of_iteration = calculate_mandelbrot(f);
	else if (ft_strcmp(input, "julia") == 0)
		no_of_iteration = calculate_julia(f);
	else if (ft_strcmp(input, "ship") == 0)
		no_of_iteration = calculate_burning_ship(f);
	if (no_of_iteration == f->max_iteration)
		put_color_to_pixel(f, f->win_x, f->win_y, 0x0d0d0d);
	else
		put_color_to_pixel(f, f->win_x, f->win_y, (f->color * no_of_iteration));
}
