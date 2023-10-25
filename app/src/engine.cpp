#include "engine.h"

Engine::Engine(int width, int height)
    : App(width, height)
{
}

void Engine::render()
{
  glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  // rendering
}
