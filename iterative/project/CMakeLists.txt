cmake_minimum_required(VERSION 3.4)
project(IT1)

add_subdirectory(src)
include_directories(include)
message("IT1_INCLUDE_DIRS = ${IT1_SRC_INCLUDE_DIRS}")
message("IT1_LIBRARIES = ${IT1_SRC_LIBRARIES}")
set_source_files_properties(main.c PROPERTIES COMPILE_OPTIONS "-lm")

add_executable(${PROJECT_NAME} main.c)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wpedantic -Wextra -Werror -lm")

target_include_directories(${PROJECT_NAME} PUBLIC ${IT1_INCLUDE_DIRS} ${IT1_SRC_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${IT1_LIBRARIES} ${IT1_SRC_LIBRARIES} m)

add_subdirectory(tests)
