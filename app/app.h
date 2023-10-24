#pragma once

#define SDL_MAIN_HANDLED
#define GL_GLEXT_PROTOTYPES
#include <SDL.h>
#include <SDL_opengl.h>

class App 
{
public:
    App(int width, int height);
    ~App();
    void run();
protected:
    bool m_quit = false;

    SDL_Window *m_window = nullptr;
    SDL_GLContext  m_context = nullptr;
};