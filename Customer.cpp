#include "Customer.hpp"
#include <stdexcept>

using namespace std;

Customer::Customer(const string& name, int age, int accountNumber, double initialBalance)
    : Person(name, age), accountNumber(accountNumber), balance(initialBalance) {}

void Customer::deposit(double amount) {
    if (amount <= 0) throw invalid_argument("Deposit amount must be positive.");
    balance += amount;
}

void Customer::withdraw(double amount) {
    if (amount <= 0) throw invalid_argument("Withdrawal amount must be positive.");
    if (amount > balance) throw runtime_error("Insufficient balance.");
    balance -= amount;
}

double Customer::getBalance() const {
    return balance;
}

void Customer::displayInfo() const {
    Person::displayInfo();
    cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
}
