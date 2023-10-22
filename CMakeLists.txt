cmake_minimum_required(VERSION 3.20)

project(yibtaglang)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCE_FILES src/*.cpp)
file(GLOB HEADER_FILES src/*.hpp)

add_executable(yiblang ${SOURCE_FILES} ${HEADER_FILES})