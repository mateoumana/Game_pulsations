cmake_minimum_required(VERSION 3.10.2)

project(software1)

#comment
include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

file(GLOB SOURCES "src/*.cpp")

add_executable(software1.bin ${SOURCES})
