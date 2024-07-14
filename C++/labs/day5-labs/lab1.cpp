#include <iostream>

int main() {

  std::string text = "the cycle of life is a cycle of cycles";

  auto index = 0;
  index = text.find("cycle ", index);
  while (index != std::string::npos) {
    text.replace(index, 5, "circle");
    index = text.find("cycle ", index);
    std::cout << index << std::endl;
  }

  std::cout << text << std::endl;
  index = 0;
  index = text.find("circle ", index);
  std::cout << index << std::endl;
  text = text.insert((index - 1), " great");
  std::cout << text << std::endl;
  index = text.find("circle ", index);
  index = text.find("circle ", index + 1);
  std::cout << index << std::endl;
  text = text.insert((index), "never-ending ");
  std::cout << text << std::endl;

  return 0;
}