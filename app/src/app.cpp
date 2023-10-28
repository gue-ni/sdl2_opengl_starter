#include "app.h"

#include <cassert>
#include <iostream>
#include <string>

const std::string vertex_shader_source = R"(
#version 330 core
layout (location = 0) in vec3 a_pos;
layout (location = 1) in vec3 a_normal;
layout (location = 2) in vec2 a_tex;

uniform mat4 transform;
out vec2 uv;
out vec3 color;

void main() {
  uv = a_tex;
  color = (a_normal + vec3(1.0)) / 2.0;
  gl_Position = transform * vec4(a_pos, 1.0);
}
)";

const std::string fragment_shader_source = R"(
#version 330 core
out vec4 FragColor;

in vec3 color;
in vec2 uv;

uniform sampler2D tex;

void main() {
  FragColor = vec4(color, 1.0);
  FragColor = vec4(texture(tex, uv).rgb, 1.0);
}
)";

App::App(int width, int height)
    : Window(width, height)
{
  m_shader = std::make_unique<gl::Shader>(vertex_shader_source, fragment_shader_source);

  constexpr glm::vec3 size = glm::vec3(0.25f);

  const std::vector<gl::Vertex> quad_vertices = {
      {{-size.x, size.y, 0}, {0, 0, 1}, {0, 1}},  // top left
      {{-size.x, -size.y, 0}, {0, 0, 1}, {0, 0}}, // bottom left
      {{size.x, size.y, 0}, {0, 0, 1}, {1, 1}},   // top right

      {{size.x, size.x, 0}, {0, 0, 1}, {1, 1}},   // top right
      {{-size.x, -size.y, 0}, {0, 0, 1}, {0, 0}}, // bottom left
      {{size.x, -size.y, 0}, {0, 0, 1}, {1, 0}},  // bottom right
  };

  const std::vector<gl::Vertex> cube_vertices = {
      {{-size.x, size.y, size.z}, {0, 0, 1}, {0, 1}},  // top left
      {{-size.x, -size.y, size.z}, {0, 0, 1}, {0, 0}}, // bottom left
      {{size.x, size.y, size.z}, {0, 0, 1}, {1, 1}},   // top right

      {{size.x, size.y, size.z}, {0, 0, 1}, {1, 1}},   // top right
      {{-size.x, -size.y, size.z}, {0, 0, 1}, {0, 0}}, // bottom left
      {{size.x, -size.y, size.z}, {0, 0, 1}, {1, 0}},  // bottom right

      {{-size.x, size.y, -size.z}, {0, 0, -1}, {0, 1}},
      {{-size.x, -size.y, -size.z}, {0, 0, -1}, {0, 0}},
      {{size.x, size.y, -size.z}, {0, 0, -1}, {1, 1}},

      {{size.x, size.y, -size.z}, {0, 0, -1}, {1, 1}},
      {{-size.x, -size.y, -size.z}, {0, 0, -1}, {0, 0}},
      {{size.x, -size.y, -size.z}, {0, 0, -1}, {1, 0}},

      {{-size.x, size.y, -size.z}, {-1, 0, 0}, {0, 1}},
      {{-size.x, -size.y, -size.z}, {-1, 0, 0}, {0, 0}},
      {{-size.x, size.y, size.z}, {-1, 0, 0}, {1, 1}},

      {{-size.x, size.y, size.z}, {-1, 0, 0}, {1, 1}},
      {{-size.x, -size.y, -size.z}, {-1, 0, 0}, {0, 0}},
      {{-size.x, -size.y, size.z}, {-1, 0, 0}, {1, 0}},

      {{size.x, size.y, -size.z}, {1, 0, 0}, {0, 1}},
      {{size.x, -size.y, -size.z}, {1, 0, 0}, {0, 0}},
      {{size.x, size.y, size.z}, {1, 0, 0}, {1, 1}},

      {{size.x, size.y, size.z}, {1, 0, 0}, {1, 1}},
      {{size.x, -size.y, -size.z}, {1, 0, 0}, {0, 0}},
      {{size.x, -size.y, size.z}, {1, 0, 0}, {1, 0}},

      {{-size.x, size.y, -size.z}, {0, 1, 0}, {0, 1}},
      {{-size.x, size.y, size.z}, {0, 1, 0}, {0, 0}},
      {{size.x, size.y, -size.z}, {0, 1, 0}, {1, 1}},

      {{size.x, size.y, -size.z}, {0, 1, 0}, {1, 1}},
      {{-size.x, size.y, size.z}, {0, 1, 0}, {0, 0}},
      {{size.x, size.y, size.z}, {0, 1, 0}, {1, 0}},

      {{-size.x, -size.y, -size.z}, {0, -1, 0}, {0, 1}},
      {{-size.x, -size.y, size.z}, {0, -1, 0}, {0, 0}},
      {{size.x, -size.y, -size.z}, {0, -1, 0}, {1, 1}},

      {{size.x, -size.y, -size.z}, {0, -1, 0}, {1, 1}},
      {{-size.x, -size.y, size.z}, {0, -1, 0}, {0, 0}},
      {{size.x, -size.y, size.z}, {0, -1, 0}, {1, 0}},
  };

  m_vbo = std::make_unique<gl::VertexBuffer>();
  m_vao = std::make_unique<gl::VertexArrayObject>();

  m_vao->bind();
  m_vbo->bind();

  m_vbo->buffer(cube_vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(gl::Vertex), (void *)offsetof(gl::Vertex, Position));
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(gl::Vertex), (void *)offsetof(gl::Vertex, Normal));
  glEnableVertexAttribArray(1);

  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(gl::Vertex), (void *)offsetof(gl::Vertex, TexCoord));
  glEnableVertexAttribArray(2);

  m_vao->unbind();

  m_texture = gl::Texture::load("../assets/container.jpg");
}

void App::render(float dt)
{
  m_time += dt;
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);

  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  float speed = 40.0f;
  glm::mat4 transform = glm::mat4(1.0f);
  transform = glm::rotate(transform, glm::radians(m_time * speed * 1.0f), glm::vec3(0.0, 0.0, 1.0));
  transform = glm::rotate(transform, glm::radians(m_time * speed * 1.5f), glm::vec3(0.0, 1.0, 0.0));
  transform = glm::rotate(transform, glm::radians(m_time * speed * 2.0f), glm::vec3(1.0, 0.0, 0.0));

  m_texture->bind(0);

  m_shader->bind();
  m_shader->set_uniform("transform", transform);
  m_shader->set_uniform("tex", 0);
  m_vao->bind();
  glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
}

void App::keydown(SDL_Keycode key)
{
  switch (key)
  {
  case SDLK_ESCAPE:
  {
    m_quit = true;
    break;
  }
  default:
    break;
  }
}
