cmake_minimum_required(VERSION 3.2)

add_executable(matrix main.cpp)
set_target_properties(matrix PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQIRED ON)

if(MSVC)
	target_compile_options(matrix PRIVATE /W4)
else()
	target_compile_options(matrix PRIVATE -Wall -Wextra -Werror)
endif()

install(TARGETS matrix RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})

set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})

set(CPACK_PACKAGE_CONTACT gavl.andr96@gmail.com)

include(CPack)
