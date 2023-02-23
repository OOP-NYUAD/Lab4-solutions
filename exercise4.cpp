/*Extend the functionality of class Account from previous lab to implement 
two more bank account types. Create CurrentAccount and SavingsAccount. Sa-
vings account should have additional members to set the interest rate (per
 annum) and calculate the profit on the balance per month. Both account t-
 ypes should have a utility method to print the statement that displays t-
 he number of withdrawals, number of deposits made, and the final account 
 balance (maintain data members to store such information in derived clas-
 ses).*/

#include <iostream>
#include <string>
#include "Account.h" // I modified this a bit

class CurrentAccount : public Account{
protected:
    int numOfWithdrawals;
    int numOfDeposits;

public:
    CurrentAccount(double b = 0){
        balance = b;
        numOfDeposits = 0;
        numOfWithdrawals = 0;
    }

    void debit(double amount){
        if(amount > balance){
            cout << "amount withdrawn exceeds the current balance!\n";
            return;
        }

        balance -= amount;
        numOfWithdrawals++;
    }

    void credit(double amount){
        if(amount < 0){
            cout << "can't credit a negative amount\n";
            return;
        }

        balance += amount;
        numOfDeposits++;
    }

    virtual void print(){
        cout << "A/C no: " << accountNumber << " Balance = " << balance << "$\n";
        cout << "Number of withdrawls made: " << numOfWithdrawals << '\n';
        cout << "Number of deposits made: " << numOfDeposits << '\n';
    }

    int getNumOfWithdrawals() const { return numOfWithdrawals; }
    int getNumOfDeposits() const { return numOfDeposits; }
};

// since the savings account has all the things from both Account and Current Account
// we'll have the savings account inherit from CurrentAccount

class SavingsAccount : public CurrentAccount{
    float rate;
    double profit;

public:
    SavingsAccount(double b = 0, float r = 0){
        balance = b;
        rate = r;
        profit = 0;
    }

    float getRate() const{ return rate; }
    double getProfit() const{ return profit; }

    void addInterest(){
        double temp = balance * rate/1200; // 1/12 to convert from annual to monthly, 1/100 to convert from percentage to decimal
        profit += temp;
        balance += temp;
    }

    void print(){
        cout << "A/C no: " << accountNumber << " Balance = " << balance << "$\n";
        cout << "Number of withdrawls made: " << numOfWithdrawals << '\n';
        cout << "Number of deposits made: " << numOfDeposits << '\n';
        cout << "Total profit made from " << rate << "\% interest rate: " << profit << '\n';
    }
};

int main(){
    SavingsAccount s(100, 5);
    SavingsAccount s2(1000, 2);

    s.credit(100);
    s.credit(200);
    s.addInterest();
    s.print();

    cout << '\n';

    s2.debit(100);
    s2.credit(2000);
    s2.addInterest();
    s2.print();

    return 0;
}