cmake_minimum_required(VERSION 3.2)

add_library(libmatrix STATIC lib_matrix.cpp lib_matrix.h)
set_target_properties(libmatrix  PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
target_include_directories(libmatrix PRIVATE ${CMAKE_BINARY_DIR})

if(MSVC)
	target_compile_options(libmatrix PRIVATE /W4)
else()
 	target_compile_options(libmatrix PRIVATE -Wall -Wextra -Werror)
endif()
