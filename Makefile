NAME = cub3D
NAME_BONUS = cub3D_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilibft -I$(MLX_LINUX_DIR)
BONUS_CFLAGS = -Wall -Wextra -Werror -Ibonus/include -Ilibft \
	-I$(MLX_LINUX_DIR)
RM = rm -rf

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
PARSER_DIR = $(SRC_DIR)/parser
DRAW_MAP_DIR = $(SRC_DIR)/draw_map
PLAYER_DIR = $(SRC_DIR)/player
OBJ_DIR = obj/
BONUS_OBJ_DIR = obj_bonus/

#MLX_MACOS_DIR = lib/mlx_macos
#MLX_MACOS = $(MLX_MACOS_DIR)/libmlx.a
#MLX_FLAGS = -L$(MLX_MACOS_DIR) -lmlx -framework OpenGL -framework AppKit

MLX_LINUX_DIR = lib/mlx_linux
MLX_LINUX = $(MLX_LINUX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_LINUX_DIR) -lmlx -lXext -lX11 -lm -lz

SRCS = main.c \
	$(PARSER_DIR)/find_player.c \
	$(PARSER_DIR)/free.c \
	$(PARSER_DIR)/parse_config.c \
	$(PARSER_DIR)/parse_map.c \
	$(PARSER_DIR)/parser.c \
	$(PARSER_DIR)/parser_helper.c \
	$(PARSER_DIR)/validate_map.c \
	$(PLAYER_DIR)/draw_player.c \
	$(PLAYER_DIR)/draw_player_orientation.c \
	$(PLAYER_DIR)/get_movement_input.c \
	$(PLAYER_DIR)/init_player.c \
	$(PLAYER_DIR)/move_player.c \
	$(DRAW_MAP_DIR)/draw_utils.c \
	$(DRAW_MAP_DIR)/draw_wall.c \
	$(DRAW_MAP_DIR)/exit_game.c \
	$(DRAW_MAP_DIR)/generate_map.c \
	$(DRAW_MAP_DIR)/graphics_init.c \
	$(DRAW_MAP_DIR)/init_game.c \
	$(DRAW_MAP_DIR)/load_images.c \
	$(DRAW_MAP_DIR)/raycasting.c

HEADERS = include/cub3d.h \
	include/parser.h \
	include/graphics.h \
	include/player.h \
	libft/libft.h

BONUS_SRCS = bonus/main_bonus.c \
	bonus/src/parser/find_player_bonus.c \
	bonus/src/parser/free_bonus.c \
	bonus/src/parser/parse_config_bonus.c \
	bonus/src/parser/parse_map_bonus.c \
	bonus/src/parser/parser_bonus.c \
	bonus/src/parser/parser_helper_bonus.c \
	bonus/src/parser/validate_map_bonus.c \
	bonus/src/player/draw_player_bonus.c \
	bonus/src/player/draw_player_orientation_bonus.c \
	bonus/src/player/get_movement_input_bonus.c \
	bonus/src/player/init_player_bonus.c \
	bonus/src/player/move_player_bonus.c \
	bonus/src/draw_map/draw_utils_bonus.c \
	bonus/src/draw_map/draw_wall_bonus.c \
	bonus/src/draw_map/exit_game_bonus.c \
	bonus/src/draw_map/generate_map_bonus.c \
	bonus/src/draw_map/graphics_init_bonus.c \
	bonus/src/draw_map/init_game_bonus.c \
	bonus/src/draw_map/load_images_bonus.c \
	bonus/src/draw_map/raycasting_bonus.c \
	bonus/src/minimap/minimap_bonus.c \
	bonus/src/minimap/move_minimap_player_bonus.c

BONUS_HEADERS = bonus/include/cub3d_bonus.h \
	bonus/include/parser_bonus.h \
	bonus/include/graphics_bonus.h \
	bonus/include/player_bonus.h \
	libft/libft.h

OBJS = $(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))
BONUS_OBJS = $(patsubst bonus/%.c,$(BONUS_OBJ_DIR)%.o,$(BONUS_SRCS))

all: $(NAME)

both: $(NAME) $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LINUX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LINUX):
	$(MAKE) -C $(MLX_LINUX_DIR)

$(OBJ_DIR)%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)%.o: bonus/%.c $(BONUS_HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(BONUS_CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	$(RM) $(BONUS_OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_LINUX_DIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS) $(LIBFT) $(MLX_LINUX)
	$(CC) $(BONUS_CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)

re: fclean all

.PHONY: all both clean fclean re bonus
