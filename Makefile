# Define ANSI escape codes for colors
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
COLOR_END := \033[0m

NAME := so_long

SRC_PATH := src/
OBJ_PATH := obj/

SRC := so_long.c parse_map.c errors.c get_next_line.c \
		get_next_line_utils.c check_map.c \
		controls.c graphics.c \

SRCS := $(addprefix $(SRC_PATH), $(SRC))
OBJ := $(SRC:.c=.o)
OBJS := $(addprefix $(OBJ_PATH), $(OBJ))

CC := gcc
CFLAGS := -Wall -Wextra -Werror
LDFLAGS := -L minilibx-linux -lmlx -framework OpenGL -framework AppKit
INC := -I ./includes -I ./minilibx-linux -I ./libft

LIBFT := ./libft/libft.a

all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "$(GREEN)Compiling $<$(COLOR_END)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo "$(GREEN)Compiling OK!$(COLOR_END)"

$(OBJ_PATH):
	@echo "$(YELLOW)Creating objects directory for $(NAME).$(COLOR_END)"
	@mkdir -p $(OBJ_PATH)
	@echo "$(YELLOW)Created.$(COLOR_END)"

$(LIBFT):
	@echo "$(YELLOW)Compiling Libft...$(COLOR_END)"
	@$(MAKE) -C ./libft

$(NAME): $(OBJS)
	@echo "$(YELLOW)Creating executable: $@.$(COLOR_END)"
	@$(CC) $(CFLAGS) $(LDFLAGS) -L./libft -lft $^ -o $@
	@echo "$(GREEN)Job's done!$(COLOR_END)"

clean:
	@echo "$(RED)Cleaning objects of $(NAME)...$(COLOR_END)"
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)Cleaned up!$(COLOR_END)"
	@$(MAKE) -C ./libft clean

fclean: clean
	@echo "$(RED)Cleaning $(NAME)$(COLOR_END)"
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) cleaned up!$(COLOR_END)"
	@$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
