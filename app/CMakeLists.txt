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
endif(WIN32)

project(app LANGUAGES CXX)

set(SDL2_DIR C:/Users/jakob/Documents/libraries/SDL2/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

#set(GLEW_LIBRARIES C:/Users/jakob/Documents/libraries/glew-2.1.0/lib/Release/x64)
#set(GLEW_INCLUDE_DIRS C:/Users/jakob/Documents/libraries/glew-2.1.0/include)

list(APPEND CMAKE_PREFIX_PATH "C:/Users/jakob/Documents/libraries/glew-2.1.0")

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)

add_executable(app 
    src/main.cpp 
    src/gl.cpp src/gl.h
    src/window.cpp src/window.h
    src/app.cpp src/app.h
)

target_link_libraries(app glm ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})

