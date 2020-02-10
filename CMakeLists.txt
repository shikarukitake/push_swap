cmake_minimum_required(VERSION 3.13)
project(cmake_testall)

set(CMAKE_CXX_STANDARD 11)

#includes
include_directories(general)
include_directories(general/libft/includes)
include_directories(general/includes)

# Libft with getline
file(GLOB_RECURSE LIBFT_FILES "${PROJECT_SOURCE_DIR}/general/libft/srcs/ft_*.c")
set(LIBFT_FILES ${LIBFT_FILES} ${LIBFT_ADD_FILES})
add_library(ft STATIC ${LIBFT_FILES})


add_executable(Main general/srcs/main.c)
target_link_libraries(Main ${PROJECT_BINARY_DIR}/libft.a)
add_dependencies(Main ft)

add_executable(cmake_testall general/srcs/checker.c)

add_executable(main general/srcs/main.c)