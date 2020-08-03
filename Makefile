# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vflander <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/02 17:32:34 by vflander          #+#    #+#              #
#    Updated: 2020/08/03 08:32:21 by vflander         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

CFLAGS = -Wall -Wextra -Werror -g

# just to make easy switching to clang for testing
CC = gcc

SRC = ft_printf.c

OBJ = $(SRC:%.c=%.o)

LIB_PATH = libft

all: $(NAME)

# each single object files depends only on single source file and header¬
%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $@"

# depends on object files only
$(NAME): $(OBJ)
	@$(MAKE) -C $(LIB_PATH)
	@cp $(LIB_PATH)/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@echo "Functions added to $(NAME)"

clean:
	@$(MAKE) -C $(LIB_PATH) clean
	@rm -f $(OBJ)
	@echo "Object files cleaned"

fclean: clean
	@$(MAKE) -C $(LIB_PATH) fclean
	@rm -f $(NAME)
	@echo "$(NAME) cleaned"

re: fclean all

bonus:

# for testing with main.c
test: $(NAME)
	@$(CC) $(CFLAGS) main.c $(NAME) && ./a.out
	@rm -f ./a.out

.PHONY: all clean fclean re bonus
