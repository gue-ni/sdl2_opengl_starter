#include <iostream>
#include <memory>

#include "engine.h"

#include <glm/glm.hpp>
#include <glm/gtx/io.hpp>

int main(void)
{
  Engine engine(640, 480);
  engine.run();
  return 0;
}
