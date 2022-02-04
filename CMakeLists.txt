cmake_minimum_required (VERSION 3.1)

project (BoxBlock CXX)

set (CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_subdirectory (src)
