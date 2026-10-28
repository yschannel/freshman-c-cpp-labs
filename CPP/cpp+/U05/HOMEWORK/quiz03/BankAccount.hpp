#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>

class BankAccount {
private:
  int id;
  double balance;
  static int defaultBankAccount;
  static double totalBankReserve;

public:
  BankAccount();
  BankAccount(double initialbalance);
  ~BankAccount();

  void deposit(double amount);
  void withdraw(double amount);

  double getBalance() const;
  static double getTotalBankReserve();
};

#endif