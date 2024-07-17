#include <cstdlib>
#include <ctime>
#include <iostream>

class Battel_ship {

private:
  bool board[5][5] = {false};
  int gusses;
  int maxGuesses;
  int locationX, locationY;

public:
  Battel_ship(int maxguess) : maxGuesses(maxguess) {
    gusses = 0;
    srand(static_cast<unsigned>(time(0)));

    locationX = rand() % 6;
    locationY = rand() % 6;
    board[locationX][locationY] = true;
    std::cout << "you have " << (maxGuesses - gusses) << " guesses left"
              << std::endl;
    // std::cout << locationX << " " << locationY << std::endl;
  }

  bool gameover() {
    if (maxGuesses <= gusses) {
      return true;
    } else {
      return false;
    }
  }

  int getGuesses() { return gusses; }

  bool guess(int x, int y) {
    gusses++;
    if (locationX == x && locationY == y) {
      std::cout << "you have reached the battel ship" << std::endl
                << "you have won " << std::endl;
      return true;
    } else if (locationX == (x + 1) || locationX == (x - 1) ||
               locationY == (y + 1) || locationY == (y - 1)) {

      std::cout << "you are near the battelship" << std::endl;
      std::cout << "you have " << (maxGuesses - gusses) << " guesses left"
                << std::endl;
      return false;
    } else {

      std::cout << "you missed" << std::endl;
      std::cout << "you have " << (maxGuesses - gusses) << " guesses left"
                << std::endl;
      return false;
    }
  }
};

int main() {
  std::cout << "Welcome to Battel ship" << std::endl;
  int x, y;
  Battel_ship game(5);
  bool won = false;
  while (!(game.gameover()) && !(won)) {
    std::cout << "please enter your guess" << std::endl;
    std::cin >> x;
    std::cin >> y;
    won = game.guess(x, y);
  }

  return 0;
}