#include <chrono>
#include <iostream>
#include <thread>

void beep(int delay, bool &state) {
  while (state) {
    std::cout << '\a' << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(delay));
  }
}
int main() {
  bool state = true;
  int delay = 3;
  std::thread beeep(beep, delay, std::ref(state));
  std::cin.get();
  state = false;
  beeep.join();
  return 0;
}
