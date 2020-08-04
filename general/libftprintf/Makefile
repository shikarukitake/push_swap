# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdagger <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 14:21:49 by sdagger           #+#    #+#              #
#    Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

LIBFT_DIR = libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

SRC = exp_util.c            \
      color_util.c          \
      flags_parser.c        \
      float_util.c          \
      ft_ldtoa.c            \
      ft_printf.c           \
      ft_putwchar.c         \
      get_digit.c           \
      get_float.c           \
      get_float_part.c      \
      get_int_part.c        \
      long_arithmetic.c     \
      precision_parser.c    \
      print_basic.c         \
      print_char.c          \
      print_d_buf.c         \
      print_digit_buf.c     \
      print_e_buf.c         \
      print_f_buf.c         \
      print_float.c         \
      print_hex.c           \
      print_oct.c           \
      print_other.c         \
      print_sd_buf.c        \
      print_str.c           \
      print_ud.c            \
      print_util.c          \
      print_ws.c            \
      printf_constants.c    \
      round_float.c         \
      size_parser.c         \
      spec_format_parser.c  \
      spec_util.c           \
      special_float_values.c \
      specificator.c        \
      type_func_table.c     \
      type_parser.c         \
      util.c                \
      width_parser.c        \
      ft_str_find.c \
		ft_min.c \
		ft_max.c \
		ft_strdup.c \
		ft_memset.c \
		ft_strchri.c \
		ft_itoa_base.c \
		ft_lltoa_base.c \
		ft_ulltoa_base.c \
		ft_atoi.c \
		ft_exit.c \
		ft_bzero.c \
		ft_isdigit.c \
		ft_power.c \
		ft_memalloc.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_str_func_not_find.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strcspn.c \
		ft_strlen.c \
		ft_strrev.c \
		ft_strsub.c \
		ft_isspace.c \
		ft_memcmp.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_strcpy.c \
		ft_strnew.c \
		ft_strncpy.c \
		ft_uitoa_base.c \
		ft_lstdelone.c \
		ft_putnbr_fd.c \
		ft_putnbr.c \
		ft_lstdel.c \
		ft_lstiter.c \
		ft_striter.c \
		ft_quicksort.c \
		ft_striteri.c \
		ft_strtrimn.c \
		ft_toupper.c \
		ft_strstr.c \
		ft_isascii.c \
		ft_strmapi.c \
		ft_lstsize.c \
		ft_strtrim.c \
		ft_putendl.c \
		ft_strncmp.c \
		ft_pow.c \
		ft_lstmap.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_lstfind.c \
		ft_memmove.c \
		ft_strnstr.c \
		ft_strequ.c \
		ft_strjoin_free.c \
		ft_strdel.c \
		ft_lstadd.c \
		ft_strsplit.c \
		ft_strrchr.c \
		ft_memccpy.c \
		ft_strncat.c \
		ft_memcpy.c \
		ft_lstnew.c \
		ft_strchrn.c \
		ft_lst_pb.c \
		ft_isalpha.c \
		ft_strlcat.c \
		ft_swap.c \
		ft_strmap.c \
		ft_bubblesort.c \
		ft_error.c \
		ft_get_next_line.c \
		ft_strjoin.c \
		ft_putendl_fd.c \
		ft_memdel.c \
		ft_strclr.c \
		ft_tolower.c \
		ft_strnequ.c \
		ft_strsub_free.c \
		ft_isalnum.c \

SRCS = $(addprefix srcs/, $(SRC))

OBJ = $(SRCS:.c=.o)

INC = ./includes/

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INC) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
