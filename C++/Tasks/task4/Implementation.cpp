#include "ImplementationAccount.h"
#include <ctime>
#include <iostream>

int Account::m_noOfAccounts = 0;
int Account::m_totalAmount = 0;
int Account::m_totalNbDeposites = 0;
int Account::m_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : m_amount(initial_deposit), m_noOfDeposits(0), m_noOfWithdrawals(0) {
  m_accountIndex = m_noOfAccounts++;
  m_totalAmount += initial_deposit;
}

Account::~Account() {
  m_noOfAccounts--;
  m_totalAmount -= m_amount;
}

int Account::getNoOfAccounts(void) { return m_noOfAccounts; }
int Account::getTotalAmount(void) { return m_totalAmount; }
int Account::getNbDeposits(void) { return m_totalNbDeposites; }
int Account::getNoOfWithdrawals(void) { return m_totalNbWithdrawals; }
void Account::displayAccountInfo(void) {
  m_displayTimestamp();

  std::cout << "Accounts: " << getNoOfAccounts() << "; "
            << "Total: " << getTotalAmount() << "; "
            << "Deposits: " << getNbDeposits() << "; "
            << "Withdrawals: " << getNoOfWithdrawals() << std::endl;
}

void Account::makeDeposite(int deposite) {
  m_amount += deposite;
  m_totalAmount += deposite;
  m_noOfDeposits++;
  m_totalNbDeposites++;
}
bool Account::makeWithdrawal(int withdrawal) {
  if (m_amount > withdrawal) {
    m_amount -= withdrawal;
    m_totalAmount -= withdrawal;
    m_noOfWithdrawals++;
    m_noOfWithdrawals++;
    return true;
  } else {
    return false;
  }
}
int Account::checkAmount(void) const { return m_amount; }
void Account::displayStatus(void) const {

  std::cout << "Index: " << m_accountIndex << "; " << "Amount: " << m_amount
            << "; " << "Deposits: " << m_noOfDeposits << "; "
            << "Withdrawals: " << m_noOfWithdrawals << std::endl;
}

void Account::m_displayTimestamp(void) {

  std::time_t now = std::time(nullptr);
  std::tm *tm_ptr = std::localtime(&now);
  std::cout << '[' << (tm_ptr->tm_year + 1900) << '-' << (tm_ptr->tm_mon + 1)
            << '-' << tm_ptr->tm_mday << ' ' << tm_ptr->tm_hour << ':'
            << tm_ptr->tm_min << ':' << tm_ptr->tm_sec << "] ";
}
