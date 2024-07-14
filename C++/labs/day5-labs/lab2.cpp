#include <iostream>
#include <string>

std::string func(std::string &src, std::string &find, std::string &repl) {

  int index = 0;

  index = src.find(find, index);
  while (index != std::string::npos) {
    src.replace(index, 5, repl);
    index = src.find(find, index);
  }

  return src;
}

int main() {
  std::string src, find, repl;
  std::cout << "please enter string" << std::endl;
  getline(std::cin, src);
  std::cout << "please enter a word to replace " << std::endl;
  getline(std::cin, find);
  std::cout << "please enter the replacment word" << std::endl;
  getline(std::cin, repl);

  std::cout << src << std::endl;

  src = func(src, find, repl);

  std::cout << src << std::endl;

  return 0;
}