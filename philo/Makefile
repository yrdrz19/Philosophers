# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 12:10:15 by yaperalt          #+#    #+#              #
#    Updated: 2025/05/27 12:37:58 by yaperalt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ANSI color codes for Makefile
BLACK   := \033[0;30m
RED     := \033[0;31m
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
MAGENTA := \033[0;35m
CYAN    := \033[0;36m
WHITE   := \033[0;37m
RESET   := \033[0m

BOLD_BLACK   := \033[1;30m
BOLD_RED     := \033[1;31m
BOLD_GREEN   := \033[1;32m
BOLD_YELLOW  := \033[1;33m
BOLD_BLUE    := \033[1;34m
BOLD_MAGENTA := \033[1;35m
BOLD_CYAN    := \033[1;36m
BOLD_WHITE   := \033[1;37m

# Makefile for Philosophers
NAME = philo
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
OBJS_DIR = obj/
MKDIR = mkdir -p
SRCS = src/main.c

OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))


# Rules
# $@ Automatic variable: it stands for the target name
# $^ Automatic variable: meaning "all prerequisites" listed to the right of
# the colon in your rule
$(NAME): $(OBJS)
	@echo "$(GREEN)Linking object files...$(RESET)"
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(BOLD_GREEN)Executable created!$(RESET)"

$(OBJS_DIR)%.o: src/%.c
	@$(MKDIR) $(OBJS_DIR)
	@echo "$(BOLD_YELLOW)Compiling source file into object file...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@echo "$(BOLD_RED)Deleting object files folder...$(RESET)"
	@$(RM) $(OBJS_DIR)

fclean: clean
	@echo "$(BOLD_MAGENTA)Removing executable...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.phony: all clean fclean re
