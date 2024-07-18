#include <iostream>

template <typename T> class DynamicArray {

private:
  T *arr;

  int capacity;

  int currentsize;

public:
  DynamicArray() {
    capacity = 1;
    currentsize = 0;
    arr = new T[capacity];
  }

  DynamicArray(int size) {
    capacity = size;
    currentsize = 0;
    arr = new T[capacity];
  }

  DynamicArray(int size, T value) {
    capacity = size;
    currentsize = size;
    arr = new T[capacity];

    for (int i = 0; i < currentsize; ++i) {
      arr[i] = value;
    }
  }

  DynamicArray(int size, T *values) {
    capacity = size;
    currentsize = size;
    arr = new T[capacity];

    for (int i = 0; i < currentsize; ++i) {
      arr[i] = values[i];
    }
  }

  DynamicArray(const DynamicArray &otherobj) {
    capacity = otherobj.capacity;
    currentsize = otherobj.currentsize;
    arr = new T[capacity];
    for (int i = 0; i < currentsize; ++i) {
      arr[i] = otherobj.arr[i];
    }
  }

  void resize() {

    capacity = capacity * 2;
    T *newarr = new T[capacity];

    for (int i = 0; i < currentsize; ++i) {
      newarr[i] = arr[i];
    }

    arr = newarr;
  }

  void pushback(T value) {
    if (currentsize < capacity) {
      arr[currentsize] = value;
      currentsize++;
    } else {
      this->resize();
      arr[currentsize] = value;
      currentsize++;
    }
  }

  T popback() {
    T value = arr[currentsize];
    currentsize--;
    return value;
  }

  void print() {

    std::cout << "the elements of the array is " << std::endl;

    for (int i = 0; i < currentsize; ++i) {
      std::cout << arr[i] << std::endl;
    }
  }

  void insertAt(int index, T value) {

    if (currentsize >= capacity) {
      resize();
    }

    for (int i = currentsize; i > index; --i) {
      arr[i] = arr[i - 1];
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

  void insertMiddle(T value) {
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

  DynamicArray<double> arr(5, new double[5]{1, 2, 3, 4, 5});
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

  DynamicArray<double> arr2;
  arr2 = arr;
  arr2.pushback(1000);
  arr2.print();

  arr.print();

  return 0;
}