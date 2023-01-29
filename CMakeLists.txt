cmake_minimum_required(VERSION 3.24)
project(beeio)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_library(beeio SHARED ${SOURCES})

add_executable(main main.cpp)
target_link_libraries(main beeio)
