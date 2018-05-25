# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sderet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 15:33:21 by sderet            #+#    #+#              #
#    Updated: 2018/05/25 17:05:20 by sderet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c in_fun.c print_char.c print_int.c print_ptr.c prints.c print_signed_int.c
HEAD = ft_printf.h
LIBS = -L./libft -lft
FRAMEW =
OBJ = $(SRCS:%.c=%.o)
CC = clang 
CFLAGS = 

all: $(NAME)

debug: CFLAGS += -g
debug: all

$(NAME): libft/libft.o $(OBJ)
	@ar rc $(NAME) libft/*.o $(OBJ)
	@ranlib $(NAME)
	@echo "Successfully compiled $(NAME)"

libft/libft.o:
	@$(MAKE) -C libft/ objects
	@$(MAKE) -C libft
	@echo "Successfully compiled libft"

$(OBJ): %.o: %.c $(HEAD)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "Successfully compiled object for $<"

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C libft $@
	@echo "$(NAME) clean successful"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft $@
	@echo "$(NAME) fclean successful"

re: fclean all