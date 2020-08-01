# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayellin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 14:21:49 by ayellin           #+#    #+#              #
#    Updated: 2019/10/26 15:04:29 by ayellin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit

LIBFT_DIR = libft

LIBFT = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = solution.c reading.c tetraminos.c validate.c main.c

OBJ = $(SRC:.c=.o)

INC = ./$(LIBFT_DIR)/includes/

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT)
		$(CC) $(CFLAGS) -I $(INC) -o $(NAME) $(OBJ) $(LIBFT_DIR)/$(LIBFT)
%.o: %.c
	    $(CC) $(CFLAGS) -I $(INC) -c -o $@ $<

$(LIBFT_DIR)/$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/$(LIBFT)

re: fclean all
