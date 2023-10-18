#include <iostream>

#include "my_lib.h"

#include <glm/glm.hpp>

int main(void)
{
  std::cout << "hello world!" << std::endl;

  std::cout << my_lib::sum(1,2) << std::endl;

  auto a = my_lib::add(glm::vec3(1.0f), glm::vec3(2.0f));

  return 0;
}