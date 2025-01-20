#include "BankSystem.hpp"

using namespace std;

BankSystem::~BankSystem() {
    for (Customer* customer : customers) delete customer;
    for (BankEmployee* employee : employees) delete employee;
}

void BankSystem::addCustomer(const string& name, int age, int accountNumber, double initialBalance) {
    customers.push_back(new Customer(name, age, accountNumber, initialBalance));
}

void BankSystem::addEmployee(const string& name, int age, const string& position) {
    employees.push_back(new BankEmployee(name, age, position));
}

void BankSystem::displayCustomers() const {
    for (const Customer* customer : customers) {
        customer->displayInfo();
        cout << "------------------\n";
    }
}

void BankSystem::displayEmployees() const {
    for (const BankEmployee* employee : employees) {
        employee->displayInfo();
        cout << "------------------\n";
    }
}

Customer* BankSystem::findCustomer(int accountNumber) {
    for (size_t i = 0; i < customers.size(); ++i) { // Explicitly using indices
        if (customers[i]->getAccountNumber() == accountNumber) {
            return customers[i];
        }
    }
    return nullptr; // If no customer is found
}


