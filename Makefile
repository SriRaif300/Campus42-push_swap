# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 10:07:56 by cgaratej          #+#    #+#              #
#    Updated: 2024/03/21 11:45:31 by cgaratej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
CC= cc
CFLAGS= -Wall -Werror -Wextra
RM= rm -f
INCLUDE= inc/push_swap.h Makefile
GREEN= \033[0;32m

SRC= src/push_swap.c \
	src/error_control.c \
	src/utils_stack.c \
	src/utils_sort.c \
	src/fill_stack.c \
	commands/swap.c \
	commands/push.c \
	commands/rotate.c \
	commands/reverse.c

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INLCUDE)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\n$(GREEN)Create $(NAME) ✔\n"

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re