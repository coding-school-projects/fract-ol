/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:01:40 by pchennia          #+#    #+#             */
/*   Updated: 2024/04/14 17:02:31 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>  // for exit()
# include <unistd.h> // for write()
# include <stdbool.h> // for boolean
# include <math.h> // for fabs()
# include "mlx/mlx.h"

// Window, Image size and Maximum iterations
# define WIN_SIZE 1000
# define MAX_ITERATIONS 60

// keys
# define ESC_KEY 53
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define UP_ARROW 126
# define DOWN_ARROW 125
# define PLUS 24
# define MINUS 27
# define C 8
# define D 2

// Mouse
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_display
{
	void	*mlx_ptr; // Magical mlx pointer
	void	*win_ptr; // window pointer
	void	*img_ptr; //pointer to image struct
	void	*img_info_ptr; //points to the actual pixels
	int		bits_per_pixel;
	int		endian;
	int		line_len;
	char	*input;
	int		max_iteration;
	int		win_x;
	int		win_y;
	double	img_x;
	double	img_y;
	double	complex_x;
	double	complex_y;
	double	img_size;
	int		color;
	double	real;
	double	imaginary;
	double	julia_x;
	double	julia_y;
}			t_display;

// Display_image
int		display_image(t_display *f, char *input);
void	calculate_fractal(t_display *f, char *input);

// Keys and Mouse Handler
void	keys_and_mouse_handler(t_display *f);
int		handle_keypress(int key, t_display *f);
int		handle_mousemove(int mouse_move, int win_x, int win_y, t_display *f);
int		close_window(t_display *f);
void	initialize_variables(t_display *f);

// Helper functions
int		ft_strcmp(char *s1, char *s2);
bool	is_integer_string(const char *str);
double	atodbl(char *s);
void	error_message(void);

#endif
