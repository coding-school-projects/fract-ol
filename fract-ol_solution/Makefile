NAME  = fractol

HEADER = fractol.h

CFILES = main.c display_image.c keys_and_mouse_handler.c helper_functions.c

OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

#  Minilibx linkers
MINLIBX = -lmlx -framework OpenGL -framework AppKit

RED=\033[0;31m
GREEN=\033[0;32m

%.o: %.c
		@ $(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES)
		@ gcc $(CFLAGS) $(OFILES) $(MINLIBX) -o $(NAME)
		@ echo "$(GREEN)Fractol compiled!"

norm:
	norminette $(CFILES) $(HEADER)

clean:
	@ $(RM) $(OFILES)
	@ echo "$(RED)Fractol object files cleaned!"

fclean: clean
	@ $(RM) $(NAME)
	@ echo "$(RED)Fractol executable files cleaned!"

re: fclean all
	@ echo "$(GREEN)Fractol RE_compiled!"

.PPHONY:all clean fclean re
