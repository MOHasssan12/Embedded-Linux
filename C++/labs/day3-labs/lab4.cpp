#include <cstdlib>
#include <iostream>

enum DataType {
  Int,
  Double,
  Char

};

class VPointerArray {
private:
  int size;
  void **vptr;

public:
  VPointerArray(int num) : size(num) { vptr = new void *[size]; }

  void set(int index, void *var, DataType data) { vptr[index] = }
  void get() {}
  int get_size() { return size; }

  ~VPointerArray() { delete[] vptr; }
};

int main() { return 0; }