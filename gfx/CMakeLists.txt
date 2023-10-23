cmake_minimum_required(VERSION 3.16)
project(gfx LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    glm GIT_REPOSITORY 
    https://github.com/g-truc/glm.git
)
FetchContent_MakeAvailable(glm)

#FetchContent_Declare(
#    imgui
#    GIT_REPOSITORY https://github.com/ocornut/imgui.git
#    GIT_TAG master
#)
#FetchContent_MakeAvailable(imgui)

if(WIN32)
FetchContent_Declare(
  SDL2
  URL https://www.libsdl.org/release/SDL2-2.26.5.tar.gz
  URL_HASH MD5=47f22c109070431ecccd90abd3c0ab6e
)
FetchContent_MakeAvailable(SDL2)
#set(SDL2_DIR ${SDL2_SOURCE_DIR})

set(SDL2_INCLUDE_DIRS C:/Users/jakob/Documents/Projects/cpp_cmake_template/build/_deps/sdl2-src/include/)




find_file(SDL2_INCLUDE_DIRS NAME SDL.h HINTS SDL2)

#FetchContent_Declare(
#    gl3w
#    GIT_REPOSITORY https://github.com/bwrsandman/gl3w.git
#    GIT_TAG master
#)
#FetchContent_MakeAvailable(gl3w)

else()
endif()

#find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

add_library(gfx STATIC gfx.cpp gfx.h app.cpp app.h)

target_include_directories(gfx PUBLIC . ${SDL2_INCLUDE_DIRS})
#target_include_directories(gfx PUBLIC ${SDL2_INCLUDE_DIRS})
#target_include_directories(gfx PUBLIC ${OPENGL_INCLUDE_DIR})
#target_include_directories(gfx PUBLIC ${SDL2_INCLUDE_DIR})


target_link_libraries(gfx PUBLIC glm::glm ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})

#message(SEND_ERROR "hello")
#message(SEND_ERROR "libs = ${SDL2_LIBRARIES}")
#message(SEND_ERROR "dirs = ${SDL2_INCLUDE_DIRS}")





