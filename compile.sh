#!/bin/bash

gcc fdf.c parse.c points.c set_map.c rotate.c set_env.c draw_line.c draw_slopes.c libft/libft.a minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
