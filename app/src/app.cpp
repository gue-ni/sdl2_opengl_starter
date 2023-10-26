#include "app.h"

#include <cassert>
#include <iostream>
#include <string>

const std::string vertex_shader_source = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
void main() {
  gl_Position = vec4(aPos, 1.0);
}
)";

const std::string fragment_shader_source = R"(
#version 330 core
out vec4 FragColor;
void main() {
  FragColor = vec4(0,1,0,1);
}
)";

App::App(int width, int height)
    : Window(width, height)
{
  m_shader = std::make_unique<gl::Shader>(vertex_shader_source, fragment_shader_source);
}

void App::render()
{
  glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  // rendering
}
