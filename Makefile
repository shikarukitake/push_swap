NAME_1 = checker
NAME_2 = push_swap
LIBFT_A = libft.a

SR_LI_1 = checker.c dynamic_array.c commands.c commands2.c commands3.c ft_strsplit.c reading.c service.c stack.c
SR_LI_2 = push_swap.c dynamic_array.c commands.c commands2.c commands3.c ft_strsplit.c reading.c service.c stack.c \
			get_commands.c service_ps.c sort_two_and_three.c init.c how_rotate.c chunks.c sort_all.c sort_five.c \
			service_ps2.c

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

COMPILER := gcc
HDRPATH := ./general/includes -I./general/libft/includes
IFLAGS := -I$(HDRPATH)
CFLAGS := -Wall -Wextra -Werror

OBJECT_LIB = ./general/libft

LIBFT = ./general/libft/libft.a
LIBS = -L./general/libft -l_ft


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
	@make -C ./general/libft

clean:
	@rm -rf $(OBJECT_DIR_1)
	@rm -rf $(OBJECT_DIR_2)
	@make -C ./general/libft clean
	@rm -rf $(OBJECT_PF)

fclean: clean
	@make -C ./general/libft fclean
	@/bin/rm -f $(NAME_1)
	@/bin/rm -f $(NAME_2)

re: fclean all