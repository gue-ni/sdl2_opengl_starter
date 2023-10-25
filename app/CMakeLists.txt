cmake_minimum_required(VERSION 3.16)

include(FetchContent)

FetchContent_Declare(
    glm GIT_REPOSITORY 
    https://github.com/g-truc/glm.git
)
FetchContent_MakeAvailable(glm)

if(WIN32)
    # FetchContent_Declare(
    #     SDL2
    #     #URL https://www.libsdl.org/release/SDL2-2.26.5.tar.gz
    #     #URL_HASH MD5=47f22c109070431ecccd90abd3c0ab6e
    #     URL     https://www.libsdl.org/release/SDL2-devel-2.0.14-VC.zip
    #     URL_MD5 2b521c5ec247955dc342235d06ebd874
    # )
    # FetchContent_MakeAvailable(SDL2)
    # message(SEND_ERROR "src = ${SDL2_SOURCE_DIR}")
    # set(SDL2_DIR ${SDL2_SOURCE_DIR}/cmake)

    set(SDL2_DIR C:/Users/jakob/Documents/libraries/SDL2/cmake)

endif(WIN32)

project(app LANGUAGES CXX)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)

add_executable(app 
    src/main.cpp 
    src/app.cpp src/app.h
    src/engine.cpp src/engine.h
)

target_link_libraries(app glm ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})

