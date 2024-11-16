NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I./libft

SRCS = src/main.c \
		src/display/display_info.c src/display/display_player.c\
		src/game/game_play.c \
		src/gnl/get_next_line.c src/gnl/get_next_line_utils.c \
		src/init/init_data.c \
		src/parse/parse_color_line.c src/parse/parse_cub_file.c src/parse/parse_map_line.c src/parse/parse_texture_line.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./minilibx
MLX_LIB = $(MLX_DIR)/libmlx.a

GTEST_DIR = /usr/local
GTEST_LIBS = $(GTEST_DIR)/lib/libgtest.a $(GTEST_DIR)/lib/libgtest_main.a -pthread  # 直接指定

UNIT_TEST_NAME = unit_tests
UNIT_TEST_SRC = test/unit/unit.cpp

E2E_TEST_SCRIPT = test/e2e/runner.sh

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lm -lXext -lX11

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

$(MLX_LIB):
	make -C $(MLX_DIR)

all: $(NAME)

$(UNIT_TEST_NAME): $(UNIT_TEST_SRC)
	g++ $(CFLAGS) -o $(UNIT_TEST_NAME) $(UNIT_TEST_SRC) -I$(GTEST_DIR)/include $(GTEST_LIBS)

unit_test: $(UNIT_TEST_NAME)
	./$(UNIT_TEST_NAME)

e2e_test:
	chmod +x $(E2E_TEST_SCRIPT)
	./$(E2E_TEST_SCRIPT)

clean:
	rm -f $(OBJS) $(UNIT_TEST_NAME)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

re: fclean all