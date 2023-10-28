#pragma once

#define SDL_MAIN_HANDLED
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

class Window
{
public:
    struct Clock
    {
        uint64_t last, now;
        float delta = 0.0f;
        void init() { now = SDL_GetPerformanceCounter(); }
        void tick()
        {
            last = now;
            now = SDL_GetPerformanceCounter();
            uint64_t freqency = SDL_GetPerformanceFrequency();
            delta = static_cast<float>(now - last) / static_cast<float>(freqency);
        }
    };

    Window(int width, int height);
    ~Window();
    void run();

protected:
    bool m_quit = false;
    SDL_Window *m_window = nullptr;
    SDL_GLContext m_context = nullptr;
    Clock m_clock;

    void poll_events();

    virtual void render(float dt);
    virtual void keydown(SDL_Keycode key);
    virtual void keyup(SDL_Keycode key);
    virtual void mousemotion(int xrel, int yrel);
};