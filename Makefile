# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 10:07:56 by cgaratej          #+#    #+#              #
#    Updated: 2024/04/03 11:38:59 by cgaratej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
CC= cc
CFLAGS=  -Wall -Werror -Wextra
RM= rm -f
INCLUDE= inc/push_swap.h Makefile
GREEN= \033[0;32m
RED = \033[31m

SRC= commands/swap.c \
	commands/push.c \
	commands/rotate.c \
	commands/reverse.c \
	src/push_swap.c \
	src/error_control.c \
	src/utils_stack.c \
	src/utils_sort.c \
	src/utils_push.c \
	src/fill_stack.c \
	src/sort.c

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INLCUDE)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\n$(GREEN)$(NAME) Create ✔\n"

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<
	@echo "$(GREEN)File $< compiled ✔\033[0m"
	
clean:
	@$(RM) $(OBJ)
	@echo "$(RED)Deleted .o files\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) Deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re