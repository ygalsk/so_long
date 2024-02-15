# Name of the binary
NAME 		= libft.a

# Compiler and flags
CC 			= cc
CFLAGS 	= -g -Wall -Werror -Wextra

# Source files
SRCS 		=	$(wildcard ./*.c)	
# Header files
HEADERS = libft.h

# Object files
OBJS 		= $(SRCS:.c=.o)

# Default target
all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo $(GREEN)"Linking $(NAME)"$(DEFAULT);

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Remove all object files
clean:
	@rm -f $(OBJS)
	@echo $(RED)"Removing object files"$(DEFAULT);

# Remove all files
fclean: clean
	@rm -f $(NAME)
	@echo $(RED)"Removing $(NAME)"$(DEFAULT);

# Rebuild everything
re: fclean all
	@echo $(GREEN)"Rebuilding everything"$(DEFAULT);

.PHONY: all clean fclean re

# Colours
DEFAULT = "\033[39m"
GREEN		= "\033[32m"
RED			= "\033[31m"
