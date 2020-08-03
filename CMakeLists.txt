cmake_minimum_required(VERSION 3.13)
project(cmake_testall)

set(CMAKE_CXX_STANDARD 11)

# includes
include_directories(general)
include_directories(general/libftprintf/includes)
include_directories(general/includes)

# Libft
file(GLOB_RECURSE LIBFT_FILES "${PROJECT_SOURCE_DIR}/general/libftprintf/srcs/*.c")
set(LIBFT_FILES ${LIBFT_FILES} ${LIBFT_ADD_FILES})
add_library(ft STATIC ${LIBFT_FILES})

# Main
add_executable(Main general/srcs/main.c)
target_link_libraries(Main ${PROJECT_BINARY_DIR}/libft.a)
add_dependencies(Main ft)

# Checker
add_executable(checker general/includes/checker.h general/srcs/stack.c general/srcs/dynamic_array.c general/srcs/service.c general/srcs/reading.c general/srcs/commands.c general/srcs/commands2.c general/srcs/commands3.c general/srcs/ft_strsplit.c)
target_link_libraries(checker ${PROJECT_BINARY_DIR}/libft.a)
add_dependencies(checker ft)

# PushSwap
add_executable(push_swap general/srcs/push_swap.c general/includes/checker.h general/srcs/stack.c general/srcs/dynamic_array.c general/srcs/service.c general/srcs/reading.c general/srcs/commands.c general/srcs/commands2.c general/srcs/commands3.c general/srcs/ft_strsplit.c general/includes/push_swap.h general/srcs/get_commands.c general/srcs/service_ps.c general/srcs/sort_two_and_three.c general/srcs/init.c general/srcs/chunks.c general/srcs/how_rotate.c general/srcs/sort_five.c general/srcs/sort_all.c general/srcs/service_ps2.c general/srcs/how_rotate2.c general/srcs/stack2.c)
target_link_libraries(push_swap ${PROJECT_BINARY_DIR}/libft.a)
add_dependencies(push_swap ft)

add_executable(main general/srcs/main.c)