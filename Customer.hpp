#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include "Person.hpp"

using namespace std;

class Customer : public Person {
private:
    int accountNumber;
    double balance;

public:
    Customer(const string& name, int age, int accountNumber, double initialBalance);
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;
    void displayInfo() const override;
    int getAccountNumber() const {
    return accountNumber;
}

};

#endif
