#include <iostream>

using namespace std;

class Account{
  int accountNumber;
  double balance;

  static int numOfAccounts;

public:
  Account(double balance = 0){
      accountNumber = numOfAccounts++;
      this->balance = balance;
  }

  int getAccountNumber(){ return accountNumber; }
  double getBalance(){ return balance; } 

  void debit(double amount){
    if(amount > balance){
      cout << "amount withdrawn exceeds the current balance!\n";
      return;
    }
  }

  void credit(double amount){
    if(amount < 0){
      cout << "can't credit a negative amount\n";
      return;
    }

    balance += amount;
  }

  void print(){
    cout << "A/C no: " << accountNumber << " Balance = " << balance << "$\n";
  }
};

int Account::numOfAccounts = 0;
