#ifndef BANKSYSTEM_HPP
#define BANKSYSTEM_HPP

#include <vector>
#include "Customer.hpp"
#include "BankEmployee.hpp"

using namespace std;

class BankSystem {
private:
    vector<Customer*> customers;
    vector<BankEmployee*> employees;

public:
    ~BankSystem();
    void addCustomer(const string& name, int age, int accountNumber, double initialBalance);
    void addEmployee(const string& name, int age, const string& position);
    void displayCustomers() const;
    void displayEmployees() const;
    Customer* findCustomer(int accountNumber);
};

#endif
