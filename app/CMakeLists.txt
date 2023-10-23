cmake_minimum_required(VERSION 3.16)
project(template-app LANGUAGES CXX)

add_executable(app main.cpp)

target_link_libraries(app PUBLIC gfx)

