#include <iostream>

#include <SDL.h>
#include <SDL_opengl.h>

#include "my_lib.h"

#include <glm/glm.hpp>

int main(void)
{
  std::cout << "hello world!" << std::endl;

  std::cout << my_lib::sum(1,2) << std::endl;

  auto a = my_lib::add(glm::vec3(1.0f), glm::vec3(2.0f));

    SDL_Init( SDL_INIT_VIDEO );

    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 2 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

  
  static const int width = 800;
  static const int height = 600;
  SDL_Window * window = SDL_CreateWindow( "", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
  SDL_GLContext context = SDL_GL_CreateContext( window );

  SDL_GL_DeleteContext( context );
  SDL_DestroyWindow( window );
  SDL_Quit();

  return 0;
}
