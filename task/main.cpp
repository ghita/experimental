#include <iostream>
#include "task.h"
int main() {
  std::cout << "Hello, World!" << std::endl;

  task<int()> task1 = [](){ return 1;};

  std::cout << task1();
}