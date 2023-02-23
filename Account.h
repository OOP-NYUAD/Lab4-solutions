#include <iostream>

using namespace std;

class Account{
protected: // made the variables protected
  int accountNumber;
  double balance;

private: // this one can stay private
  static int numOfAccounts;

public:
  Account(double balance = 0){
      accountNumber = numOfAccounts++;
      this->balance = balance;
  }

  int getAccountNumber(){ return accountNumber; }
  double getBalance(){ return balance; } 

  // made this function virtual
  virtual void debit(double amount){
    if(amount > balance){
      cout << "amount withdrawn exceeds the current balance!\n";
      return;
    }

    balance -= amount; // fixed this mistake
  }

  // made this function virtual
  virtual void credit(double amount){
    if(amount < 0){
      cout << "can't credit a negative amount\n";
      return;
    }

    balance += amount;
  }

  // made this function virtual
  virtual void print(){
    cout << "A/C no: " << accountNumber << " Balance = " << balance << "$\n";
  }
};

int Account::numOfAccounts = 0;
