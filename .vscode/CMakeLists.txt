cmake_minimum_required(VERSION 3.16)
project(QtApp)

set(CMAKE_CXX_STANDARD 17)

# Tell CMake where Qt is installed
set(CMAKE_PREFIX_PATH "C:/Qt/6.9.2/mingw_64")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(QtApp main.cpp)
target_link_libraries(QtApp Qt6::Widgets)
