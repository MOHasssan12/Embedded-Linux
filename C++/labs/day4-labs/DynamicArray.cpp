#include <iostream>
/*

Implement a class for a dynamic array (Vector)
    * Containing the following functions
        * resize() - resize the array to double the size
        * pushback(value) - add the value to the end of the array
        * popback() - remove the last element from the array
        * removeAt(index) - remove the element at the given index
        * insertAt(index, value) - insert the value at the given index and shift
the elements to the right
        * insertMiddle(value) - insert the value in the middle of the array
        * removeMiddle() - remove the middle element from the array
        * size() - return the size of the array
        * print() - print the array

    * The following overload constructors:
        * DynamicArray() - default constructor with capacity of 1
        * DynamicArray(size) - constructor with given capacity
        * DynamicArray(size, value) - constructor with given capacity and
initial value for all elements --> DynamicArray arr(5, 10);
        * DynamicArray(size, values) - constructor with given capacity and
initial values --> DynamicArray arr(5, new int[5]{1, 2, 3, 4, 5});
        * DynamicArray(arr) - copy constructor

    * Appropriate destructor

    - Private members:
        * array - pointer to the array
        * capacity - capacity of the array
        * currentSize - current size of the array


*/

class DynamicArray {

private:
  int *arr;

  int capacity;

  int currentsize;

public:
  DynamicArray() {
    capacity = 1;
    currentsize = 0;
    arr = new int[capacity];
  }

  DynamicArray(int size) {
    capacity = size;
    currentsize = 0;
    arr = new int[capacity];
  }

  DynamicArray(int size, int value) {
    capacity = size;
    currentsize = size;
    arr = new int[capacity];

    for (int i = 0; i < currentsize; ++i) {
      arr[i] = value;
    }
  }

  DynamicArray(int size, int *values) {
    capacity = size;
    currentsize = size;
    arr = new int[capacity];

    for (int i = 0; i < currentsize; ++i) {
      arr[i] = values[i];
    }
  }

  DynamicArray(DynamicArray &otherobj) {
    capacity = otherobj.capacity;
    currentsize = otherobj.currentsize;
    arr = new int[capacity];
    for (int i = 0; i < currentsize; ++i) {
      arr[i] = otherobj.arr[i];
    }
  }

  void resize() {

    capacity = capacity * 2;
    int *newarr = new int[capacity];

    for (int i = 0; i < currentsize; ++i) {
      newarr[i] = arr[i];
    }

    arr = newarr;
  }

  void pushback(int value) {
    if (currentsize < capacity) {
      arr[currentsize] = value;
      currentsize++;
    } else {
      this->resize();
      arr[currentsize] = value;
      currentsize++;
    }
  }

  int popback() {
    int value = arr[currentsize];
    currentsize--;
    return value;
  }

  void print() {

    std::cout << "the elements of the array is " << std::endl;

    for (int i = 0; i < currentsize; ++i) {
      std::cout << arr[i] << std::endl;
    }
  }

  void insertAt(int index, int value) {

    for (int i = currentsize; i > index; --i) {
      arr[i + 1] = arr[i];
    }

    arr[index] = value;
    currentsize++;
  }

  void removeAt(int index) {

    for (int i = index; i < currentsize - 1; ++i) {
      arr[i] = arr[i + 1];
    }
    currentsize--;
  }

  void insertMiddle(int value) {
    int middel_index = currentsize / 2;

    insertAt(middel_index, value);
  }

  void removeMiddle() {
    int middel_index = currentsize / 2;
    removeAt(middel_index);
  }
};

int main()

{

  DynamicArray arr(5, new int[5]{1, 2, 3, 4, 5});
  arr.print();
  arr.pushback(6);
  arr.print();
  arr.insertAt(2, 10);
  arr.print();
  arr.removeAt(3);
  arr.print();
  arr.insertMiddle(99);
  arr.print();
  arr.removeMiddle();
  arr.print();

  // case for copy constructor

  DynamicArray arr2;
  arr2 = arr;
  arr2.pushback(1000);
  arr2.print();

  arr.print();

  return 0;
}