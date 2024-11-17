#include <iostream>
#include <map>
#include <string>

using namespace std;

class Bank {
private:
    struct Account {
        string name;
        double balance;
    };
    map<int, Account> accounts;

public:
    void createAccount(int accNumber, string name, double initialDeposit) {
        if (accounts.count(accNumber) == 0) {
            accounts[accNumber] = {name, initialDeposit};
            cout << "Account created for " << name << " with initial balance: " << initialDeposit << endl;
        } else {
            cout << "Account number already exists!" << endl;
        }
    }

    void deposit(int accNumber, double amount) {
        if (accounts.count(accNumber)) {
            accounts[accNumber].balance += amount;
            cout << "Deposited " << amount << ". New balance: " << accounts[accNumber].balance << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void withdraw(int accNumber, double amount) {
        if (accounts.count(accNumber)) {
            if (accounts[accNumber].balance >= amount) {
                accounts[accNumber].balance -= amount;
                cout << "Withdrawn " << amount << ". New balance: " << accounts[accNumber].balance << endl;
            } else {
                cout << "Insufficient funds!" << endl;
            }
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void checkBalance(int accNumber) {
        if (accounts.count(accNumber)) {
            cout << "Account balance for " << accounts[accNumber].name << ": " << accounts[accNumber].balance << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }
};

int main() {
    Bank bank;
    bank.createAccount(101, "Alice", 5000.0);
    bank.deposit(101, 1500.0);
    bank.withdraw(101, 2000.0);
    bank.checkBalance(101);

    bank.createAccount(102, "Bob", 3000.0);
    bank.withdraw(102, 4000.0);
    bank.checkBalance(102);

    return 0;
}
