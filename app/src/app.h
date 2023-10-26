#pragma once

#include "Window.h"
#include "gl.h"

#include <memory>

class App : public Window
{
public:
  App(int width, int height);
  void render() override;

private:
  std::unique_ptr<gl::Shader> m_shader = nullptr;
  std::unique_ptr<gl::VertexArrayObject> m_vao = nullptr;
  std::unique_ptr<gl::VertexBuffer> m_vbo = nullptr;
};
