class ParkingSystem {
public:
  int count_big;
  int count_medium;
  int count_small;

  ParkingSystem(int big, int medium, int small) {
    count_big = big;
    count_medium = medium;
    count_small = small;
  }

  bool addCar(int carType) {
    bool statues;
    switch (carType) {
    case 1:
      if (count_big != 0) {
        count_big--;
        statues = true;
      } else {
        statues = false;
      }
      break;
    case 2:
      if (count_medium != 0) {
        count_medium--;
        statues = true;
      } else {
        statues = false;
      }
      break;
    case 3:
      if (count_small != 0) {
        count_small--;
        statues = true;
      } else {
        statues = false;
      }
      break;
    }

    return statues;
  }
};
