#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount()  { balance = 0.0; }
    void Deposit(double amount);
    void Withdraw(double amount);
    double GetBalance();
};

void BankAccount::Deposit(double amount) {
    balance = balance + amount;
}

void BankAccount::Withdraw(double amount) {
    if (amount > balance) {
        cout << "Insufficient funds." << endl;
    }
    else {
        balance = balance - amount;
    }
}

double BankAccount::GetBalance() {
    return balance;
}

int main() {
    BankAccount acc;

    acc.Deposit(1000);
    cout << "Current balance: " << acc.GetBalance() << endl;

    acc.Withdraw(500);
    cout << "Current balance: " << acc.GetBalance() << endl;

    acc.Withdraw(600);   // more than remaining balance
    cout << "Current balance: " << acc.GetBalance() << endl;

    return 0;
}