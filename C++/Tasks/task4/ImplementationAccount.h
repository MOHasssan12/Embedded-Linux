#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class Account {
public:
  using acc = Account;

  static int getNoOfAccounts(void);
  static int getTotalAmount(void);
  static int getNbDeposits(void);
  static int getNoOfWithdrawals(void);
  static void displayAccountInfo(void);

  Account(int initial_deposite);
  ~Account(void);

  void makeDeposite(int deposite);
  bool makeWithdrawal(int withdrawal);
  int checkAmount(void) const;
  void displayStatus(void) const;

private:
  static int m_noOfAccounts;
  static int m_totalAmount;
  static int m_totalNbDeposites;
  static int m_totalNbWithdrawals;

  static void m_displayTimestamp(void);

  int m_accountIndex;
  int m_amount;
  int m_noOfDeposits;
  int m_noOfWithdrawals;

  Account(void);
};

#endif