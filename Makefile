NAME_1 = checker

NAME_2 = push_swap
LIBFT_A = libftprintf.a

SR_LI_1 = checker.c \
          dynamic_array.c \
          commands.c \
          commands2.c \
          commands3.c \
          reading.c \
          service.c \
          service2.c \
          stack.c \
          stack2.c \
          service_ps.c \

SR_LI_2 = push_swap.c \
			dynamic_array.c \
			commands.c \
			commands2.c \
			commands3.c \
			reading.c \
			service.c \
			service2.c \
			stack.c \
			stack2.c \
			get_commands.c \
			service_ps.c \
			sort_two_and_three.c \
			init.c \
			how_rotate.c \
			how_rotate2.c \
			chunks.c \
			sort_all.c \
			sort_five.c \
			service_ps2.c \

SOURCES_DIR = ./general/srcs/

SRCS_LI_1 = $(addprefix $(SOURCES_DIR), $(SR_LI_1))
OBJECT_DIR_1 = objects1/
OBJ_LIST_LI_1 = $(patsubst %.c, %.o, $(SR_LI_1))
OBJ_LI_1 = $(addprefix $(OBJECT_DIR_1), $(OBJ_LIST_LI_1))

SRCS_LI_2 = $(addprefix $(SOURCES_DIR), $(SR_LI_2))
OBJECT_DIR_2 = objects2/
OBJ_LIST_LI_2 = $(patsubst %.c, %.o, $(SR_LI_2))
OBJ_LI_2 = $(addprefix $(OBJECT_DIR_2), $(OBJ_LIST_LI_2))

HEADER_DIR = ./general/includes/

# ft_printf
#OBJECT_PF = ./ft_printf/objects
#
#LIB_PF = ft_printf/libftprintf.a
#LIBS_PF = -L./ft_printf -lftprintf
# --------

COMPILER := gcc
HDRPATH := ./general/includes -I./general/libftprintf/includes
IFLAGS := -I$(HDRPATH)
CFLAGS := -Wall -Wextra -Werror

LIB_DIR = ./general/libftprintf

LIBFT = ./general/libftprintf/libftprintf.a
LIBS = -L./general/ft_libftprintf -l_ftprintf


all: $(NAME_1) $(NAME_2)

$(NAME_1): $(LIBFT) $(LIB_PF) $(OBJECT_DIR_1) $(OBJ_LI_1)
	@$(COMPILER) $(CFLAGS) $(IFLAGS) $(LIBFT) $(LIBS_PF) $(OBJ_LI_1) -o $(NAME_1)

$(NAME_2): $(LIBFT) $(LIB_PF) $(OBJECT_DIR_2) $(OBJ_LI_2)
	@$(COMPILER) $(CFLAGS) $(IFLAGS) $(LIBFT) $(LIBS_PF) $(OBJ_LI_2) -o $(NAME_2)

$(OBJECT_DIR_1):
	@mkdir -p $(OBJECT_DIR_1)

$(OBJECT_DIR_1)%.o : $(SOURCES_DIR)%.c $(HEADERS)
	@$(COMPILER) $(CFLAGS) -c $(IFLAGS) $< -o $@

$(OBJECT_DIR_2):
	@mkdir -p $(OBJECT_DIR_2)

$(OBJECT_DIR_2)%.o : $(SOURCES_DIR)%.c $(HEADERS)
	@$(COMPILER) $(CFLAGS) -c $(IFLAGS) $< -o $@

$(LIBFT):
	@make -C $(LIB_DIR)

clean:
	@rm -rf $(OBJECT_DIR_1)
	@rm -rf $(OBJECT_DIR_2)
	@make -C $(LIB_DIR) clean
#	@make -C ./ft_printf clean
	@rm -rf $(OBJECT_PF)

fclean: clean
	@make -C $(LIB_DIR) fclean
#	@make -C ./ft_printf fclean
	@/bin/rm -f $(NAME_1)
	@/bin/rm -f $(NAME_2)

re: fclean all
