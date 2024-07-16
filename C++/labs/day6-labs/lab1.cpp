#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  std::ifstream input("input.txt");
  std::ofstream output("output.txt");

  if (!input) {
    std::cerr << "Error opening input file" << std::endl;
    return 1;
  }

  std::vector<int> arr;
  std::string str;
  while (std::getline(input, str)) {
    if (!str.empty()) {
      arr.push_back(std::stoi(str));
    }
  }

  input.close();

  if (arr.empty()) {
    std::cerr << "No data to process" << std::endl;
    return 1;
  }

  int sum = 0, avg = 0, min = 0, max = 0;

  for (const auto &num : arr) {
    sum += num;
  }

  avg = sum / arr.size();

  std::sort(arr.begin(), arr.end());

  min = arr.front();
  max = arr.back();

  if (!output) {
    std::cerr << "Error opening output file" << std::endl;
    return 1;
  }

  output << "-----------------------------------------" << std::endl;
  output << "|" << std::setw(5) << std::setfill(' ') << std::right << "sum"
         << std::setw(5) << std::setfill(' ') << "|" << std::setw(5)
         << std::right << "avg" << std::setw(5) << std::setfill(' ') << "|"
         << std::setw(5) << std::right << "min" << std::setw(5)
         << std::setfill(' ') << "|" << std::setw(5) << std::right << "max"
         << std::setw(5) << std::setfill(' ') << "|" << std::endl;
  output << "-----------------------------------------" << std::endl;
  output << "|" << std::setw(5) << std::setfill(' ') << std::right << sum
         << std::setw(5) << std::setfill(' ') << "|" << std::setw(5)
         << std::right << avg << std::setw(5) << std::setfill(' ') << "|"
         << std::setw(5) << std::right << min << std::setw(5)
         << std::setfill(' ') << "|" << std::setw(5) << std::right << max
         << std::setw(5) << std::setfill(' ') << "|" << std::endl;
  output << "-----------------------------------------" << std::endl;

  output.close();

  return 0;
}
