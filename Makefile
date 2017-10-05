NAME = fdf

CFLAGS = -Wall -Werror -Wextra
CFLAGS += -I includes -I libft/includes
LDFLAGS += -L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

LIBFT := libft/libft.a 
LIBMLX := minilibx_macos/libmlx.a

FDFDR = fdf.c \
        parse.c \
        set_map.c \
        set_env.c \
        points.c \
        rotate.c \
        draw_slopes.c \
        draw_line.c \

all : $(NAME)

$(LIBFT):
        @make -C libft

$(LIBMLX):
        @make -C minilibx_macos

$(OBJ): %.o: %.c 
        @$(CC) -c $(CFLAGS) $< -o $@
        @echo "Compiled Executable"

clean:
        @rm -rf $(OBJ)
        @make -C libft clean
        @make -C minilibx_macos clean
        @echo "Object Files Removed"

fclean: clean  
        @rm -rf $(NAME)
        @make -C libft fclean
        @echo "libftfdf.a Removed"

re: fclean all


