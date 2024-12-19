NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I./libft -I./minilibx

SRCS = src/main.c \
       src/display/display_info.c src/display/display_player.c \
       src/draw/draw_floor_ceiling.c src/draw/draw_wall.c \
       src/game/game_calculate.c src/game/game_handler.c src/game/game_move.c src/game/game_play.c src/game/game_render.c \
       src/gnl/get_next_line.c src/gnl/get_next_line_utils.c \
       src/init/init_data.c src/init/init_mlx.c src/init/init_ray.c src/init/init_texture.c src/init/init_wall.c\
       src/parse/parse_color_line.c src/parse/parse_cub_file_process.c src/parse/parse_cub_file.c src/parse/parse_map_line.c src/parse/parse_texture_line.c \
       src/util/util_array.c src/util/util_error.c src/util/util_free.c src/util/util_image.c src/util/util_texture.c src/util/util.c \
       src/validate/validate_args.c src/validate/validate_line.c src/validate/validate_map_position.c src/validate/validate_map_wall_analyzer.c src/validate/validate_map_wall_util.c src/validate/validate_map_wall.c src/validate/validate_map.c

OBJ_DIR = obj
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

LIBFT = ./libft/libft.a
MLX_LINUX = ./minilibx/libmlx.a
MLX_DARWIN = ./minilibx/libmlx_Darwin.a
X11_LIBS = /usr/X11R6/lib/libX11.dylib /usr/X11R6/lib/libXext.dylib

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	MLX_TARGET = $(MLX_DARWIN)
    MLX_LIBS = $(MLX_DARWIN) -framework OpenGL -framework AppKit $(X11_LIBS)
else
	MLX_TARGET = $(MLX_LINUX)
    MLX_LIBS = $(MLX_LINUX) -L/usr/lib/x86_64-linux-gnu -lX11 -lXext -lm
endif

$(NAME): $(LIBFT) $(MLX_TARGET) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_LIBS)

$(LIBFT):
	$(MAKE) -C libft

$(MLX_DARWIN):
	$(MAKE) -C minilibx

$(MLX_LINUX):
	$(MAKE) -C minilibx

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C minilibx clean

re: fclean all

.PHONY: all clean fclean re