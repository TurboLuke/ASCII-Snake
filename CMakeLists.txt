cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(compile_flags INTERFACE)
if("${CMAE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(compile_flags INTERFACE -Wall -Wextra -Wpedantic -Wconversion -fno-elide-constructors)
endif()

file(GLOB_RECURSE ASCII_SNAKE "src/*")
add_executable(ascii_snake ${ASCII_SNAKE})
target_link_libraries(ascii_snake compile_flags)