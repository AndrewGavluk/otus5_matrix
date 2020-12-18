cmake_minimum_required(VERSION 3.2)
enable_testing()

find_package(GTest REQUIRED)

add_executable(gtest_matrix test_matrix.cpp)
target_include_directories(gtest_matrix PUBLIC ../libs)

set_target_properties(gtest_matrix 
	PROPERTIES 
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS})
	
				
if(MSVC)
	target_compile_options(gtest_matrix PRIVATE /W4)
else()
	target_compile_options(gtest_matrix PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
							
target_link_libraries(gtest_matrix gtest pthread)
							
add_test(gtest_matrix_test1 gtest_matrix)
