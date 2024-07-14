#include <cmath>
#include <iostream>

class Calculator {

private:
  float result;
  float add(float n1, float n2) { return n1 + n2; }
  float sub(float n1, float n2) { return n1 - n2; }
  float div(float n1, float n2) { return n1 / n2; }
  float mul(float n1, float n2) { return n1 * n2; }

  float power(float n1, float n2) { return pow(n1, n2); }

  float squareroot(float n1) { return sqrt(n1); }

public:
  Calculator() {}

  float calc(float n1, float n2, char op) {

    switch (op) {
    case '+':
      result = add(n1, n2);
      break;
    case '-':
      result = sub(n1, n2);
      break;
    case '/':
      result = div(n1, n2);
      break;
    case '*':
      result = mul(n1, n2);
      break;
    case '^':
      result = power(n1, n2);
      break;
    }
    return result;
  }

  float calc(float n1, char op) {
    result = sqrt(n1);
    return result;
  }
};

int main() {

  Calculator num;

  std::cout << num.calc(5, 5, '+') << std::endl;
  // std::cout << "please enter the first num " << std::endl;

  return 0;
}