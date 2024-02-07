cmake_minimum_required(VERSION 3.10)
project(opengl_learning VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(opengl_learning src/tutorial4.cpp)

find_package(glad CONFIG REQUIRED)
target_link_libraries(opengl_learning PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(opengl_learning PRIVATE glfw)

find_package(Stb REQUIRED)
target_include_directories(opengl_learning PRIVATE ${Stb_INCLUDE_DIR})
