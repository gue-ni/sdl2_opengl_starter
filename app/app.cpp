#include "app.h"

App::App(int width, int height)
{
  SDL_Init(SDL_INIT_VIDEO);

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  m_window = SDL_CreateWindow("App", 25, 25, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  m_context = SDL_GL_CreateContext(m_window);

  glViewport(0, 0, width, height);
}

App::~App()
{
  SDL_GL_DeleteContext(m_context);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

void App::run()
{
  while (!m_quit)
  {
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // rendering
    SDL_GL_SwapWindow(m_window);
  }
}