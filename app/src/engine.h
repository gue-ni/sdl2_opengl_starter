#pragma once

#include "app.h"

class Engine : public App
{
public:
  Engine(int width, int height);
  void render() override;
};
