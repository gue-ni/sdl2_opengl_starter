cmake_minimum_required(VERSION 3.16)
project(my-lib LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
    glm GIT_REPOSITORY 
    https://github.com/g-truc/glm.git
)
FetchContent_MakeAvailable(glm)

FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG master
)
FetchContent_MakeAvailable(imgui)

FetchContent_Declare(
  SDL2
  URL https://www.libsdl.org/release/SDL2-2.26.5.tar.gz
  URL_HASH MD5=47f22c109070431ecccd90abd3c0ab6e
)
FetchContent_MakeAvailable(SDL2)

add_library(my_lib STATIC my_lib.cpp my_lib.h)

target_include_directories(my_lib PUBLIC .)

target_link_libraries(my_lib PUBLIC glm::glm)


