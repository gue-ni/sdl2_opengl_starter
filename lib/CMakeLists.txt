cmake_minimum_required(VERSION 3.16)
project(my-lib LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(glm GIT_REPOSITORY https://github.com/g-truc/glm.git)
FetchContent_MakeAvailable(glm)

add_library(my_lib STATIC my_lib.cpp my_lib.h)

target_include_directories(my_lib PUBLIC .)

target_link_libraries(my_lib PUBLIC glm::glm)


