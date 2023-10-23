#pragma once

#define GL_GLEXT_PROTOTYPES
#include <SDL.h>
#include <SDL_opengl.h>

class App 
{
public:
    App();
    ~App();
protected:
    SDL_Window *m_window;
    SDL_GLContext  m_context;
};