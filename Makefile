NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I./libft -I./minilibx

SRCS = src/main.c \
       src/display/display_info.c src/display/display_player.c \
       src/draw/draw_floor_ceiling.c src/draw/draw_wall.c \
       src/game/game_calculate.c src/game/game_handler.c src/game/game_move.c src/game/game_play.c src/game/game_render.c \
       src/gnl/get_next_line.c src/gnl/get_next_line_utils.c \
       src/init/init_data.c src/init/init_mlx.c src/init/init_ray.c src/init/init_texture.c \
       src/parse/parse_color_line.c src/parse/parse_cub_file.c src/parse/parse_map_line.c src/parse/parse_texture_line.c \
       src/util/util_array.c src/util/util_error.c src/util/util_image.c src/util/util_texture.c

OBJ_DIR = obj
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

LIBFT = ./libft/libft.a
MLX_LINUX = ./minilibx/libmlx.a
MLX_DARWIN = ./minilibx/libmlx_Darwin.a
X11_LIBS = /usr/X11R6/lib/libX11.dylib /usr/X11R6/lib/libXext.dylib

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
    MLX_LIBS = $(MLX_DARWIN) -framework OpenGL -framework AppKit $(X11_LIBS)
else
    MLX_LIBS = $(MLX_LINUX) $(X11_LIBS)
endif

# 実行ファイル生成
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_LIBS)

# オブジェクトファイル生成
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# 全ビルド
all: $(NAME)

# クリーンアップ
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re