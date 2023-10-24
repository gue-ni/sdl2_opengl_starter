#include <iostream>
#include <memory>

#include "app.h"

#include <glm/glm.hpp>
#include <glm/gtx/io.hpp>

int main(void)
{
  glm::vec3 a(1.0f);
  std::cout << a << std::endl;
  
  App app(640, 480);
  app.run();
  return 0;
}
