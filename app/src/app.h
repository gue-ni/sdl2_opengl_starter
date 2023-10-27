#pragma once

#include "window.h"
#include "gfx/gfx.h"

#include <memory>

class App : public Window
{
public:


  App(int width, int height);
  void render(float dt) override;

private:
  std::unique_ptr<gl::Shader> m_shader = nullptr;
  std::unique_ptr<gl::VertexArrayObject> m_vao = nullptr;
  std::unique_ptr<gl::VertexBuffer> m_vbo = nullptr;
  std::shared_ptr<gl::Texture> m_texture = nullptr;
  float m_time = 0.0f;
};
