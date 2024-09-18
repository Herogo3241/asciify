cmake_minimum_required(VERSION 3.0)
project(AsciiArtGenerator)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(ascii_art_generator main.cpp)
target_link_libraries(ascii_art_generator ${OpenCV_LIBS})

