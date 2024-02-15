# Name of the binary
NAME     = so_long

# Existential crisis
USER     = $(shell whoami)

# Compiler and flags
CC       = cc
CFLAGS   = -g -Wall -Werror -Wextra

# MLX42 Flags
MLXFLAGS = -ldl -lglfw -pthread -lm

# Source files
SRCS     = $(wildcard libft/*.c ./*.c)

# Header files
HEADERS  = libft/libft.h

# Object files
OBJS     = $(SRCS:.c=.o)

# MLX42 library
MLX      = ./MLX42/build/libmlx42.a

# Default target
all: $(NAME)

$(NAME): $(HEADERS) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(MLX) $(MLXFLAGS) -o $(NAME) $(OBJS)
	@echo $(GREEN)"Building $(NAME)"$(DEFAULT);

# MLX42 library
$(MLX):
	@if [ ! -d "MLX42" ]; then \
      git clone https://github.com/codam-coding-college/MLX42.git && \
      cd MLX42 && cmake -B build && cmake --build build -j4; \
	fi

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Remove all object files
clean:
	@rm -f $(OBJS)
	@echo $(RED)"Removing object files"$(DEFAULT);

# Remove all files
fclean: clean
	@rm -f $(NAME)
	@rm -rf MLX42
	@echo $(RED)"Removing $(NAME) and MLX42"$(DEFAULT);

# Rebuild everything
re: fclean all
	@echo $(GREEN)"Rebuilding everything"$(DEFAULT);

.PHONY: all clean fclean re

# Colours
DEFAULT = "\033[39m"
GREEN   = "\033[32m"
RED     = "\033[31m"
