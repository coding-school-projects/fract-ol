/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:16:25 by pchennia          #+#    #+#             */
/*   Updated: 2024/04/15 09:55:45 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	display_image(t_display *f, char *input)
{
	f->win_x = 0;
	f->win_y = 0;
	while (f->win_x < WIN_SIZE)
	{
		while (f->win_y < WIN_SIZE)
		{
			calculate_fractal(f, input);
			f->win_y++;
		}
		f->win_x++;
		f->win_y = 0;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
	return (0);
}

void	create_mlx_window_and_image(t_display *f)
{
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIN_SIZE, WIN_SIZE, "Fract'ol");
	f->img_ptr = mlx_new_image(f->mlx_ptr, WIN_SIZE, WIN_SIZE);
	f->img_info_ptr = mlx_get_data_addr(f->img_ptr, &f->bits_per_pixel,
			&f->line_len, &f->endian);
}

void	initialize_variables(t_display *f)
{
	f->win_x = 0;
	f->win_y = 0;
	f->color = 0xFCBE11;
	f->img_size = 150;
	f->img_x = -4;
	f->img_y = -3;
	f->max_iteration = 100;
}

int	main(int argc, char *argv[])
{
	t_display	f;

	if ((argc == 2 && ((ft_strcmp(argv[1], "mandel") == 0)
				|| (ft_strcmp(argv[1], "ship")) == 0))
		|| (argc == 4 && ft_strcmp(argv[1], "julia") == 0))
	{
		if (ft_strcmp(argv[1], "julia") == 0)
		{
			if (is_integer_string(argv[2]) && is_integer_string(argv[3]))
			{
				f.julia_x = atodbl(argv[2]);
				f.julia_y = atodbl(argv[3]);
			}
		}
		f.input = argv[1];
		initialize_variables (&f);
		create_mlx_window_and_image(&f);
		display_image(&f, f.input);
		keys_and_mouse_handler (&f);
		mlx_loop (f.mlx_ptr);
	}
	else
		error_message();
	return (0);
}
