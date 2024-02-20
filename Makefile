NAME	=	cub3d

LIBFT_DIR	=	libft/
LIBFT_NAME	=	libft.a
LIBFT		=	$(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

INC            :=    cub3d.h
INC_DIR        :=    inc/

HEADERS        := $(addprefix $(INC_DIR), $(INC))

### PARSING ### 
PARSING			:=	textures/check_input.c textures/get_textures.c textures/check_textures.c textures/check_rgb.c textures/check_filepath.c textures/fill_textures.c\
					map/get_map.c map/check_map.c map/check_map_char.c\
					skip_empty_lines.c
PARSING_DIR		:=	parsing/
PARSING_APPEND	:=	$(addprefix $(PARSING_DIR), $(PARSING))

SRC_DIR        :=	src/
SRC            :=	debug/print_textures.c debug/print_map.c\
					main.c \
					cleaning/free_textures.c cleaning/free_split.c cleaning/free_map.c\
					utils/identificator.c utils/identificator_cardinal.c utils/isspace.c utils/line_empty.c utils/remove_backslash_n.c utils/ft_strstr.c utils/countchar.c utils/map_utils.c\
					$(PARSING_APPEND)


OBJ_DIR        :=    obj/
OBJ            :=    $(SRC:%.c=$(OBJ_DIR)%.o)

# define standard colors
_END        :=    \x1b[0m
_BOLD       :=    \x1b[1m
_UNDER      :=    \x1b[4m
_REV        :=    \x1b[7m
_GREY       :=    \x1b[30m
_RED        :=    \x1b[31m
_GREEN      :=    \x1b[32m
_YELLOW     :=    \x1b[33m
_BLUE       :=    \x1b[34m
_PURPLE     :=    \x1b[35m
_CYAN       :=    \x1b[36m
_WHITE      :=    \x1b[37m

#Compiler
CC            :=    cc
CC_FLAGS      :=   -Wall -Wextra -Werror 


all: libft ft_printf $(NAME)

$(NAME): $(OBJ) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CC_FLAGS) $(OBJ) -L ./libft -lft -o $@
	@echo "All compiled"

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS) Makefile
	@mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -I $(INC_DIR) -c $< -o $@
libft:
	@make -C libft

clean: cleanlibft
	@rm -rf $(OBJ_DIR)
	@echo "Everything removed"

fclean: fcleanlibft clean
	@rm -rf $(NAME)

cleanlibft:
	@make clean -C ${LIBFT_DIR}

fcleanlibft: cleanlibft
	@make fclean -C ${LIBFT_DIR}

re: fclean
	make all

.PHONY: all clean fclean re libft ft_printf