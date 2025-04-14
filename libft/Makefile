# Define ANSI escape codes for colors
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
COLOR_END := \033[0m

NAME := libft.a

SRC_PATH := src/
OBJ_PATH := obj/

SRC := ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
		ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
		ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
		ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c  \
		ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
		ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c  \
		ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c \
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_atof.c \
		ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_bug.c 

OBJS := $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

CC := gcc
CFLAGS := -Wall -Wextra -Werror
INC := -I ./includes

all: $(OBJ_PATH) $(OBJS) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "$(GREEN)Compiling $<$(COLOR_END)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo "$(GREEN)Compiling OK!$(COLOR_END)"

$(OBJ_PATH):
	@echo "$(YELLOW)Creating objects directory for $(NAME).$(COLOR_END)"
	@mkdir -p $(OBJ_PATH)
	@echo "$(YELLOW)Created.$(COLOR_END)"

$(NAME): $(OBJS)
	@echo "$(YELLOW)Creating library...$(COLOR_END)" 
	@ar -rcs $@ $(OBJS)
	@echo "$(GREEN)Job's done!$(COLOR_END)"

clean:
	@echo "$(RED)Cleaning objects directory...$(COLOR_END)"
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)Cleaned up!$(COLOR_END)"

fclean: clean
	@echo "$(RED)Cleaning library...$(COLOR_END)"
	@rm -f $(NAME)
	@echo "$(RED)Cleaned up!$(COLOR_END)"

re: fclean all

.PHONY: all clean fclean re

