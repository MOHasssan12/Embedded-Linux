#include <iostream>

class Vertex {
private:
  int x;
  int y;

public:
  Vertex() {
    x = (rand() % 201) - 100;
    y = (rand() % 201) - 100;
  }

  int get_x() { return x; }

  int get_y() { return y; }

  void print() { std::cout << "X = " << x << " " << "Y = " << y << std::endl; }
};

int main() {

  Vertex point1;
  Vertex point2;

  point1.print();
  point2.print();

  return 0;
}