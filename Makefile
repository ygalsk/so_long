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
						 ./bonus/keyhooks_bonus.c ./bonus/main_bonus.c ./bonus/textures_bonus.c ./bonus/screen_msgs.c ./bonus/animations.c \
						 ./bonus/animations_utils.c ./bonus/textures_utils.c ./bonus/free_utils.c
 
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
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(MLXFLAGS) $(HEADER)
	@echo $(GREEN)"Building $(NAME)"$(DEFAULT);

$(NAME_BONUS): $(HEADER) $(MLX) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(MLX) $(MLXFLAGS) $(HEADER) 
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
	@make -C libft clean
	@echo $(RED)"Removing $(NAME) object files"$(DEFAULT);

# Remove all files
fclean: clean
	@rm -f $(NAME)
	@rm -rf MLX42
	@make -C libft fclean
	@echo $(RED)"Removing $(NAME) and MLX42 "$(DEFAULT);

clean_bonus:
	@rm -f $(OBJS_BONUS)
	@make -C libft clean
	@echo $(RED)"Removing $(NAME_BONUS) object files"$(DEFAULT);

# Remove all files
fclean_bonus: clean_bonus
	@rm -f $(NAME_BONUS)
	@rm -rf MLX42
	@make -C libft fclean
	@echo $(RED)"Removing $(NAME_BONUS) and MLX42 "$(DEFAULT);

# Rebuild everything
re: fclean all
	@echo $(GREEN)"Rebuilding everything"$(DEFAULT);

re_bonus: fclean bonus
.PHONY: all clean fclean re re_bonus

# Colours
DEFAULT = "\033[39m"
GREEN   = "\033[32m"
RED     = "\033[31m"
