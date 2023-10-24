cmake_minimum_required(VERSION 3.16)
project(app LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    glm GIT_REPOSITORY 
    https://github.com/g-truc/glm.git
)
FetchContent_MakeAvailable(glm)

if(WIN32)
    #set(SDL2_DIR C:/Users/jakob/Documents/libraries/SDL2/cmake)

    FetchContent_Declare(
        SDL2
        URL https://www.libsdl.org/release/SDL2-2.26.5.tar.gz
        URL_HASH MD5=47f22c109070431ecccd90abd3c0ab6e
    )
    FetchContent_MakeAvailable(SDL2)

endif(WIN32)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)

add_executable(app main.cpp app.cpp app.h)

target_link_libraries(app glm ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})

