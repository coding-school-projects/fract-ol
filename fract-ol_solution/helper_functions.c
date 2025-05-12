/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:31:07 by pchennia          #+#    #+#             */
/*   Updated: 2024/04/14 15:59:03 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

bool	is_integer_string(const char *str)
{
	int	i;
	int	has_decimal_point;

	has_decimal_point = false;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		error_message();
	while (str[i] != '\0')
	{
		if (str[i] == '.' && has_decimal_point == false)
		{
			has_decimal_point = true;
			i++;
		}
		if (str[i] < '0' || str[i] > '9')
			error_message();
		i++;
	}
	return (true);
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		s++;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = sign * (-1);
	while (*s != '.' && *s != 0)
		integer_part = (integer_part * 10) + (*s++ - '0');
	if ('.' == *s)
		s++;
	while (*s != 0)
	{
		pow = pow / 10;
		fractional_part = fractional_part + (*s++ - '0') * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

void	error_message(void)
{
	write(1, "Usage: ./fractol <fractal>\n", 27);
	write(1, "Available fractals: mandelbrot, julia, burningship\n", 51);
	write(1, "Example:\n", 9);
	write(1, "\t./fractol mandel\n", 18);
	write(1, "\t./fractol julia -0.745429 0.05\n", 32);
	write(1, "\t./fractol ship\n", 16);
	exit (1);
}
