# Name of the binary
NAME     = so_long

NAME_BONUS = so_long_bonus

# Existential crisis
USER     = $(shell whoami)

# Compiler and flags
CC       = cc
CFLAGS   = -Wall -Werror -Wextra -g

# MLX42 Flags
MLXFLAGS = -ldl -lglfw -pthread -lm

# Source files
SRCS     = map.c check.c find_stuff.c free_and_quit.c keyhooks.c main.c textures.c

SRCS_BONUS = ./bonus/map_bonus.c ./bonus/check_bonus.c ./bonus/find_stuff_bonus.c ./bonus/free_and_quit_bonus.c \
						 ./bonus/keyhooks_bonus.c ./bonus/main_bonus.c ./bonus/textures_bonus.c
 
# Header files
HEADER  = libft/libft.a

# Object files
OBJS     = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# MLX42 library
MLX      = ./MLX42/build/libmlx42.a

# Default target
all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(HEADER) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(MLX) $(MLXFLAGS) $(HEADER) -o $(NAME) $(OBJS)
	@echo $(GREEN)"Building $(NAME)"$(DEFAULT);

$(NAME_BONUS): $(HEADER) $(MLX) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(MLX) $(MLXFLAGS) $(HEADER) -o $(NAME_BONUS) $(OBJS_BONUS)
	@echo $(GREEN)"Building $(NAME_BONUS)"$(DEFAULT);

# MLX42 library
$(MLX):
	@if [ ! -d "MLX42" ]; then \
      git clone https://github.com/codam-coding-college/MLX42.git && \
      cd MLX42 && cmake -B build && cmake --build build -j4; \
	fi

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

#Linking libft
$(HEADER):
	@make -C libft

# Remove all object files
clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
	@make -C libft clean
	@echo $(RED)"Removing $(NAME) object files"$(DEFAULT);

# Remove all files
fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -rf MLX42
	@make -C libft fclean
	@echo $(RED)"Removing $(NAME) and MLX42 "$(DEFAULT);

# Rebuild everything
re: fclean all
	@echo $(GREEN)"Rebuilding everything"$(DEFAULT);

rebonus: fclean bonus
.PHONY: all clean fclean re

# Colours
DEFAULT = "\033[39m"
GREEN   = "\033[32m"
RED     = "\033[31m"
