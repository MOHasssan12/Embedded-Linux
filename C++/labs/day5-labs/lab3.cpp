#include <iostream>
#include <vector>

std::vector<std::vector<int>> get2d(int row, int col) {
  int num;
  std::vector<std::vector<int>> vec(row);
  for (int i = 0; i < row; ++i) {
    std::cout << "Please insert elements of row " << i + 1 << ":" << std::endl;
    for (int j = 0; j < col; ++j) {
      std::cout << "Please insert element of column " << j + 1 << ":"
                << std::endl;
      std::cin >> num;
      vec[i].push_back(num);
    }
  }
  return vec;
}

void print2d(std::vector<std::vector<int>> &vec) {

  for (const auto &row : vec) {
    for (const auto &elem : row) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }
}

std::vector<std::vector<int>> transpose_func(std::vector<std::vector<int>> &vec,
                                             int row, int col) {
  std::vector<std::vector<int>> newvec(row);

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      newvec[j].push_back(vec[i][j]);
    }
  }
  return newvec;
}

int main() {

  std::vector<std::vector<int>> vec = get2d(2, 2);
  print2d(vec);
  vec = transpose_func(vec, 2, 2);
  print2d(vec);
  return 0;
}