cmake_minimum_required(VERSION 3.16)

include(FetchContent)

FetchContent_Declare(
    glm GIT_REPOSITORY 
    https://github.com/g-truc/glm.git
)
FetchContent_MakeAvailable(glm)

FetchContent_Declare(
    stb GIT_REPOSITORY 
    https://github.com/nothings/stb
)
FetchContent_MakeAvailable(stb)

if(WIN32)

    FetchContent_Declare(
        GLEW
        # URL https://sourceforge.net/projects/glew/files/glew/2.1.0/glew-2.1.0.zip
        URL https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0-win32.zip
    )
    FetchContent_MakeAvailable(GLEW)

    FetchContent_Declare(
        SDL2
        # URL https://www.libsdl.org/release/SDL2-2.26.5.tar.gz
        URL https://github.com/libsdl-org/SDL/releases/download/release-2.26.4/SDL2-devel-2.26.4-VC.zip
    )
    FetchContent_MakeAvailable(SDL2)


    #set(SDL2_DIR "${CMAKE_SOURCE_DIR}/build/_deps/sdl2-src/cmake")

    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/build/_deps/sdl2-src")
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/build/_deps/glew-src")

endif(WIN32)

project(app LANGUAGES CXX)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)

#include_directories(${CMAKE_SOURCE_DIR}/app/src)

include_directories(${CMAKE_SOURCE_DIR}/build/_deps/stb-src)

add_executable(app 
    main.cpp 
    window.cpp window.h
    app.cpp app.h
    gfx/gfx.h
    gfx/gl.cpp gfx/gl.h
    gfx/image.cpp gfx/image.h
)

target_link_libraries(app glm ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

