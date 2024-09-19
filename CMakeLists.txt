cmake_minimum_required(VERSION 3.0)
project(Asciify)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(asciify main.cpp)
target_link_libraries(asciify ${OpenCV_LIBS})


install(TARGETS asciify DESTINATION /usr/local/bin)
