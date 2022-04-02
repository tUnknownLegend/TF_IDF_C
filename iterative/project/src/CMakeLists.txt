cmake_minimum_required(VERSION 3.0.0)
project(IT1_SRC)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0")

file(GLOB SOURCES *.c)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include/)

include_directories(${PROJECT_SOURCE_DIR}/include)

message (${PROJECT_SOURCE_DIR}/../include)

add_library(${PROJECT_NAME} ${SOURCES})

set(IT1_SRC_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(IT1_SRC_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)