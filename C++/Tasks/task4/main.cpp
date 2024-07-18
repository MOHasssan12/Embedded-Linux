#include "ImplementationAccount.h"

int main() {
  Account acc1(1000);
  Account acc2(2000);

  acc1.makeDeposite(500);
  acc2.makeWithdrawal(1000);

  acc1.displayStatus();
  acc2.displayStatus();

  Account::displayAccountInfo();

  return 0;
}
