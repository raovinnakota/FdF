NAME = fdf

INCLUDE = fdf.h
LIBFT = libft/libft.a
LIBMLX := minilibx_macos/libmlx.a

CFLAGS = -Wall -Werror -Wextra
CFLAGS += -I includes -I libft/includes
LDFLAGS += -L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

FDFDR = parse.c \
        set_map.c \
        set_env.c \
        points.c \
        rotate.c \
        draw_slopes.c \
        draw_line.c \
		fdf.c \

OBJ = $(FDFDR:.c=.o)

all : $(NAME)

$(LIBFT):
	@make -C libft/

$(LIBMLX): 
	@make -C minilibx_macos

$(OBJ): %.o:%.c 
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo "Compiled Executable"

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@make -C minilibx_macos clean
	@echo "Object Files Removed"

fclean: clean  
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "libft.a Removed"

re: fclean all


