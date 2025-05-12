/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_and_mouse_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:24:30 by pchennia          #+#    #+#             */
/*   Updated: 2024/04/14 15:58:17 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int key, t_display *f)
{
	if (key == ESC_KEY)
		close_window(f);
	if (key == LEFT_ARROW)
		f->img_x = f->img_x + 42 / f->img_size;
	else if (key == RIGHT_ARROW)
		f->img_x = f->img_x - 42 / f->img_size;
	else if (key == UP_ARROW)
		f->img_y = f->img_y + 42 / f->img_size;
	else if (key == DOWN_ARROW)
		f->img_y = f->img_y - 42 / f->img_size;
	else if (key == C)
		f->color = f->color + (255 * 255 * 255) / 100;
	else if (key == D)
		initialize_variables(f);
	else if (key == PLUS)
		f->max_iteration += 10;
	else if (key == MINUS)
		f->max_iteration -= 10;
	display_image(f, f->input);
	return (0);
}

int	handle_mousemove(int mouse_move, int win_x, int win_y, t_display *f)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (mouse_move == SCROLL_UP)
	{
		f->img_x = (win_x / f->img_size + f->img_x) - (win_x
				/ (f->img_size * zoom_level));
		f->img_y = (win_y / f->img_size + f->img_y) - (win_y
				/ (f->img_size * zoom_level));
		f->img_size *= zoom_level;
	}
	else if (mouse_move == SCROLL_DOWN)
	{
		f->img_x = (win_x / f->img_size + f->img_x) - (win_x
				/ (f->img_size / zoom_level));
		f->img_y = (win_y / f->img_size + f->img_y) - (win_y
				/ (f->img_size / zoom_level));
		f->img_size /= zoom_level;
	}
	display_image(f, f->input);
	return (0);
}

int	close_window(t_display *f)
{
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	exit (1);
	return (0);
}

void	keys_and_mouse_handler(t_display *f)
{
	mlx_key_hook (f->win_ptr, handle_keypress, f);
	mlx_mouse_hook (f->win_ptr, handle_mousemove, f);
	mlx_hook (f->win_ptr, 17, 0, close_window, f);
}
