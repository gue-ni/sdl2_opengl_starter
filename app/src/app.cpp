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

  std::vector<glm::vec3> vertices = {
      {-0.5f, -0.5f, 0.0f}, // left
      {0.5f, -0.5f, 0.0f},  // right
      {0.0f, 0.5f, 0.0f}    // top
  };

  m_vbo = std::make_unique<gl::VertexBuffer>();
  m_vao = std::make_unique<gl::VertexArrayObject>();

  m_vao->bind();
  m_vbo->bind();
  m_vbo->buffer(vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void *)0);
  glEnableVertexAttribArray(0);

  m_vao->unbind();
}

void App::render()
{
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  m_shader->bind();
  m_vao->bind();
  glDrawArrays(GL_TRIANGLES, 0, 3);
}
