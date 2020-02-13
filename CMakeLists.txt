cmake_minimum_required(VERSION 3.13)
project(cmake_testall)

set(CMAKE_CXX_STANDARD 11)

# includes
include_directories(general)
include_directories(general/libft/includes)
include_directories(general/includes)

# Libft
file(GLOB_RECURSE LIBFT_FILES "${PROJECT_SOURCE_DIR}/general/libft/srcs/ft_*.c")
set(LIBFT_FILES ${LIBFT_FILES} ${LIBFT_ADD_FILES})
add_library(ft STATIC ${LIBFT_FILES})

# Main
add_executable(Main general/srcs/main.c)
target_link_libraries(Main ${PROJECT_BINARY_DIR}/libft.a)
add_dependencies(Main ft)

# Checker
add_executable(checker general/srcs/checker.c general/includes/checker.h general/srcs/stack.c general/srcs/dynamicArray.c general/srcs/service.c general/srcs/reading.c general/srcs/Commands.c general/srcs/Commands2.c general/srcs/Commands3.c)
target_link_libraries(checker ${PROJECT_BINARY_DIR}/libft.a)
add_dependencies(checker ft)

# PushSwap
add_executable(pushSwap general/srcs/pushSwap.c general/includes/checker.h general/srcs/stack.c general/srcs/dynamicArray.c general/srcs/service.c general/srcs/reading.c general/srcs/Commands.c general/srcs/Commands2.c general/srcs/Commands3.c)
target_link_libraries(pushSwap ${PROJECT_BINARY_DIR}/libft.a)
add_dependencies(pushSwap ft)

add_executable(main general/srcs/main.c)