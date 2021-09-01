cmake_minimum_required(VERSION 3.20)
project(02_OpenGLStart)

set(CMAKE_CXX_STANDARD 11)


add_executable(02_OpenGLStart main.cpp display.cpp display.h mesh.cpp mesh.h shader.cpp shader.h)
target_link_libraries(02_OpenGLStart SDL2)
target_link_libraries(02_OpenGLStart GLEW)
target_link_libraries(02_OpenGLStart GL)
