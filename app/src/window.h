#pragma once

#define SDL_MAIN_HANDLED
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

class Window
{
public:
    Window(int width, int height);
    ~Window();
    void run();

protected:
    bool m_quit = false;
    SDL_Window *m_window = nullptr;
    SDL_GLContext m_context = nullptr;

    void poll_events();
    virtual void render();
};