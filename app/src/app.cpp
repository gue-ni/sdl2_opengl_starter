#include "app.h"

#include <cassert>
#include <iostream>
#include <string>

const std::string vertex_shader_source = R"(
#version 330 core
layout (location = 0) in vec3 a_pos;
uniform mat4 transform;
out vec2 uv;
void main() {
  uv = a_pos.xy;
  gl_Position = transform * vec4(a_pos, 1.0);
}
)";

const std::string fragment_shader_source = R"(
#version 330 core
out vec4 FragColor;
in vec2 uv;
uniform sampler2D tex;
void main() {
#if 0
  vec3 color = vec3(0.5, 1.0, 0.5);
#else
  vec3 color = texture(tex, uv).rgb;
#endif
  FragColor = vec4(color, 1.0);
}
)";

App::App(int width, int height)
    : Window(width, height)
{
  m_shader = std::make_unique<gl::Shader>(vertex_shader_source, fragment_shader_source);

  std::vector<glm::vec3> vertices = {
      {-0.5f, -0.5f, 0.0f},
      {0.5f, -0.5f, 0.0f},
      {-0.5f, 0.5f, 0.0f},
      {0.5f, 0.5f, 0.0f},
  };

  m_vbo = std::make_unique<gl::VertexBuffer>();
  m_vao = std::make_unique<gl::VertexArrayObject>();

  m_vao->bind();
  m_vbo->bind();
  m_vbo->buffer(vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void *)0);
  glEnableVertexAttribArray(0);

  m_vao->unbind();

  m_texture = gl::Texture::load("../assets/container.jpg");
}

void App::render(float dt)
{
  m_time += dt;
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  float speed = 40.0f;
  glm::mat4 transform = glm::mat4(1.0f);
  transform = glm::rotate(transform, glm::radians(m_time * speed * 1.0f), glm::vec3(0.0, 0.0, 1.0));
  transform = glm::rotate(transform, glm::radians(m_time * speed * 1.5f), glm::vec3(0.0, 1.0, 0.0));

  m_texture->bind(0);

  m_shader->bind();
  m_shader->set_uniform("transform", transform);
  m_shader->set_uniform("tex", 0);
  m_vao->bind();
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}
