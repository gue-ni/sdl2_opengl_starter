#include <iostream>
#include <memory>

#include "app.h"

#include <glm/glm.hpp>
#include <glm/gtx/io.hpp>

int main(void)
{
  App engine(640, 480);
  engine.run();
  return 0;
}
