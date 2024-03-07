NAME	=	cub3D

LIBFT_DIR	=	libft/
LIBFT_NAME	=	libft.a
LIBFT		=	$(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

INC            :=    cub3d.h
INC_DIR        :=    inc/

HEADERS        := $(addprefix $(INC_DIR), $(INC))

### PARSING ###
PARSING			:=	textures/check_input.c textures/get_textures.c textures/check_textures.c textures/check_rgb.c textures/check_filepath.c textures/fill_textures.c\
					map/get_map.c map/check_map.c map/check_map_char.c map/make_map_rectangular.c map/check_map_closed.c\
					skip_empty_lines.c

PARSING_DIR		:=	parsing/
PARSING_APPEND	:=	$(addprefix $(PARSING_DIR), $(PARSING))

SRC_DIR        :=	src/
SRC            :=	debug/print_textures.c debug/print_map.c debug/print_xpm_infos.c debug/print_xpm_rgb.c\
					main.c \
					cleaning/free_textures.c cleaning/free_split.c cleaning/free_map.c cleaning/finish_reading_file.c cleaning/free_rgb.c cleaning/free_color_table.c\
					utils/identificator.c utils/identificator_cardinal.c utils/isspace.c utils/line_empty.c utils/remove_backslash_n.c utils/ft_strtrim_ending.c utils/ft_strstr.c utils/countchar.c utils/map_utils.c utils/ft_atoi_base.c\
					xpm/get_xpm_infos.c xpm/fill_xpm_rgb.c xpm/get_color_table.c xpm/rgb_to_int.c xpm/xpm_to_rgb.c\
					mlx/mlx_utils.c mlx/events.c mlx/draw.c raycasting/raycasting.c $(PARSING_APPEND)


OBJ_DIR        :=    obj/
OBJ            :=    $(SRC:%.c=$(OBJ_DIR)%.o)

#Compiler
CC            :=    cc
CC_FLAGS      :=   -Wall -Wextra -Werror -g


all: libft $(MLX) ft_printf $(NAME)

$(NAME): $(OBJ) $(FT_PRINTF) $(LIBFT) $(MLX)
	$(CC) $(CC_FLAGS) $(OBJ) -L ./libft -lft -L ./minilibx-linux -lmlx -lXext -lX11 -lm -o $@
	@echo "All compiled"

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS) Makefile
	@mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -I $(INC_DIR) -c $< -o $@

libft:
	@make -C libft

$(MLX):
	@make -C $(MLX_DIR)

clean: cleanlibft cleanmlx
	@rm -rf $(OBJ_DIR)
	@echo "Everything removed"

fclean: fcleanlibft clean
	@rm -rf $(NAME)

cleanlibft:
	@make clean -C ${LIBFT_DIR}

fcleanlibft: cleanlibft
	@make fclean -C ${LIBFT_DIR}

cleanmlx:
	@make clean -C ${MLX_DIR}

re: fclean
	make all

#test:
#	$(CC) $(CC_FLAGS) src/xpm/get_xpm_infos.c src/xpm/fill_xpm_rgb.c src/xpm/get_color_table.c src/xpm/rgb_to_int.c src/xpm/xpm_to_rgb.c src/utils/ft_atoi_base.c src/debug/print_xpm_infos.c src/debug/print_xpm_rgb.c src/cleaning/free_split.c -L ./libft -lft -I $(INC_DIR)

.PHONY: all clean fclean re libft ft_printf mlx test
