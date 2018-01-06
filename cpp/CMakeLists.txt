cmake_minimum_required(VERSION 3.9)
project(cpp)

find_package(JNI REQUIRED)

include_directories(${JNI_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp main.cpp)

target_link_libraries(cpp ${JNI_LIBRARIES})