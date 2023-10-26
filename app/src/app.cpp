#include "app.h"

#include <cassert>
#include <iostream>
#include <string>

const std::string vertex_shader_source = R"(
#version 330 core
layout (location = 0) in vec3 a_pos;
uniform mat4 transform;
void main() {
  gl_Position = transform * vec4(a_pos, 1.0);
}
)";

const std::string fragment_shader_source = R"(
#version 330 core
out vec4 FragColor;
void main() {
  vec3 color = vec3(0.5, 1.0, 0.5);
  FragColor = vec4(color, 1.0);
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

void App::render(float dt)
{
  std::cout << dt << std::endl;
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glm::mat4 transform = glm::mat4(1.0f);
  transform = glm::rotate(transform, glm::radians(45.0f), glm::vec3(0.0, 0.0, 1.0));

  m_shader->bind();
  m_shader->set_uniform("transform", transform);
  m_vao->bind();
  glDrawArrays(GL_TRIANGLES, 0, 3);
}
