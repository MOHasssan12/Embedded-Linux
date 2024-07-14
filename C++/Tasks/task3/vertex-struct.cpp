#include <cstdlib>
#include <iostream>
#include <vector>
typedef struct vertex {
  int x;
  int y;
} vertex;

int main() {
  int size;
  std::cout << "number of the required vertices" << std::endl;
  std::cin >> size;
  std::vector<vertex> vertices(size);
  int i = 0;
  while (i < size) {
    vertices[i].x = (rand() % 201) - 100;
    vertices[i].y = (rand() % 201) - 100;
    i++;
  }
  i = 0;
  while (i < size) {
    std::cout << vertices[i].x << " " << vertices[i].y << std::endl;
    i++;
  }

  return 0;
}