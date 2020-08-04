# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vflander <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/02 17:32:34 by vflander          #+#    #+#              #
#    Updated: 2020/08/04 15:14:55 by vflander         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

CFLAGS = -Wall -Wextra -Werror -g #-I $(LIBFT_PATH)

# just to make easy switching to clang for testing
CC = gcc

SRC = \
	ft_printf.c \
	printf_parse.c \
	printf_print_type_char.c \
	printf_print_type_string.c \
	printf_print_type_int.c \
	printf_print_type_hex.c

OBJ = $(SRC:%.c=%.o)

LIBFT_PATH = libft/

LIBFT = libft.a

all: $(NAME)

# each single object files depends only on single source file and header¬
%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) $(LIB) -c $< -o $@
	@echo "Compiled $@"

# depends on object files only
$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_PATH) --no-print-directory
	@cp $(LIBFT_PATH)$(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@echo "Functions added to $(NAME)"

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean --no-print-directory
	@rm -f $(OBJ)
	@echo "Printf's object files cleaned"

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean --no-print-directory
	@rm -f $(NAME)
	@echo "$(NAME) cleaned"

re: fclean all

bonus:

# for testing with main.c
test: $(NAME)
	@$(CC) $(CFLAGS) main.c $(NAME) && ./a.out | cat -e
	@rm -f ./a.out

.PHONY: all clean fclean re bonus
