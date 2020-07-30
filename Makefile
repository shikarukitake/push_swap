# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsedgeki <lsedgeki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 16:35:23 by lsedgeki          #+#    #+#              #
#    Updated: 2020/02/26 19:16:35 by lsedgeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = lem-in
LIBFT_A = lib_func.a

SR_LI = list_of_rooms.c start_and_parce.c cleaner.c input_checker.c parcer.c \
		move_ants.c algo.c pathes.c myravyi.c help_func.c \
		help_func2.c about_links.c cases.c copy_form_que.c \
		deleting.c forming_path.c help_in_ways.c

HEADER_LIST = lem_in.h structs.h

#--------
OBJECT_LIB = ./lib_func/objects

LIBFT = lib_func/lib_func.a
LIBS = -L./lib_func -l_func
#--------

#--------
OBJECT_PF = ./ft_printf/objects

LIB_PF = ft_printf/libftprintf.a
LIBS_PF = -L./ft_printf -lftprintf
#--------

#--------
SOURCES_DIR = ./sources/
SRCS_LI = $(addprefix $(SOURCES_DIR), $(SR_LI))
OBJECT_DIR = objects/
OBJ_LIST_LI = $(patsubst %.c, %.o, $(SR_LI))
OBJ_LI = $(addprefix $(OBJECT_DIR), $(OBJ_LIST_LI))
#--------

#--------
COMPILER := gcc
HDRPATH := ./headers -I./lib_func/header -I./ft_printf/headers
IFLAGS := -I$(HDRPATH)
CFLAGS := -Wall -Wextra -Werror
#--------

all: $(NAME_1)

$(NAME_1): $(LIBFT) $(LIB_PF) $(OBJECT_DIR) $(OBJ_LI)
	@$(COMPILER) $(CFLAGS) $(IFLAGS) $(LIBS) $(LIBS_PF) $(OBJ_LI) -o $(NAME_1)
	
$(OBJECT_DIR):
	@mkdir -p $(OBJECT_DIR)

$(OBJECT_DIR)%.o : $(SOURCES_DIR)%.c $(HEADERS)
	@$(COMPILER) $(CFLAGS) -c $(IFLAGS) $< -o $@ 

$(LIBFT):
	@make -C ./lib_func

$(LIB_PF):
	@make -C ./ft_printf

clean:
	@rm -rf $(OBJECT_DIR)
	@rm -rf $(OBJECT_LIB)
	@rm -rf $(OBJECT_PF)

fclean: clean
	@/bin/rm -f $(NAME_1)

re: fclean all