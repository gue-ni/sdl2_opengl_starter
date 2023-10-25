#include "engine.h"

#include <cassert>
#include <iostream>

const char *vertex_shader_source = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
void main() {
  gl_Position = vec4(aPos, 1.0);
}
)";

const char *fragment_shader_source = R"(
#version 330 core
out vec4 FragColor;
void main() {
  FragColor = vec4(0,1,0,1);
}
)";

Engine::Engine(int width, int height)
    : App(width, height)
{
  int success;
  char log[512];

  GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
  glCompileShader(vertex_shader);
  glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertex_shader, 512, NULL, log);
    std::cerr << "Error: " << log;
  }

  GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
  glCompileShader(fragment_shader);
  glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragment_shader, 512, NULL, log);
    std::cerr << "Error: " << log;
  }

  shader = glCreateProgram();
  glAttachShader(shader, vertex_shader);
  glAttachShader(shader, fragment_shader);
  glLinkProgram(shader);
  glGetProgramiv(shader, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetProgramInfoLog(shader, 512, NULL, log);
    std::cerr << "Error: " << log;
  }

  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);
}

void Engine::render()
{
  glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  // rendering
}
