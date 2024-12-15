// Bank Management System in C++

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

// Base class: Person
class Person {
protected:
    string name;
    int age;
public:
    Person(const string& name, int age) : name(name), age(age) {}
    virtual ~Person() {}
    virtual void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class: Customer
class Customer : public Person {
private:
    int accountNumber;
    double balance;
public:
    Customer(const string& name, int age, int accountNumber, double initialBalance)
        : Person(name, age), accountNumber(accountNumber), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount <= 0) throw invalid_argument("Deposit amount must be positive.");
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0) throw invalid_argument("Withdrawal amount must be positive.");
        if (amount > balance) throw runtime_error("Insufficient balance.");
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};

// Polymorphic functionality
class BankEmployee : public Person {
private:
    string position;
public:
    BankEmployee(const string& name, int age, const string& position)
        : Person(name, age), position(position) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Position: " << position << endl;
    }
};

// Bank System
class BankSystem {
private:
    vector<Customer*> customers;
    vector<BankEmployee*> employees;
public:
    ~BankSystem() {
        for (auto customer : customers) delete customer;
        for (auto employee : employees) delete employee;
    }

    void addCustomer(const string& name, int age, int accountNumber, double initialBalance) {
        customers.push_back(new Customer(name, age, accountNumber, initialBalance));
    }

    void addEmployee(const string& name, int age, const string& position) {
        employees.push_back(new BankEmployee(name, age, position));
    }

    void displayCustomers() const {
        for (const auto& customer : customers) {
            customer->displayInfo();
            cout << "------------------\n";
        }
    }

    void displayEmployees() const {
        for (const auto& employee : employees) {
            employee->displayInfo();
            cout << "------------------\n";
        }
    }

    Customer* findCustomer(int accountNumber) {
        for (auto& customer : customers) {
            if (customer->getBalance() == accountNumber) {
                return customer;
            }
        }
        return nullptr;
    }
};

int main() {
    BankSystem bank;

    // Adding customers
    bank.addCustomer("Ricardo Quaresma", 30, 1001, 5000.0);
    bank.addCustomer("Rafa Silva", 28, 1002, 3000.0);

    // Adding employees
    bank.addEmployee("Atiba Hutchinson", 35, "Manager");
    bank.addEmployee("Mario Gomez", 40, "Clerk");

    // Display customers and employees
    cout << "Bank Customers:\n";
    bank.displayCustomers();

    cout << "Bank Employees:\n";
    bank.displayEmployees();

    // Perform transactions
    try {
        Customer* customer = bank.findCustomer(1001);
        if (customer) {
            customer->deposit(2000.0);
            customer->withdraw(1000.0);
            cout << "Updated Info for Customer 1001:\n";
            customer->displayInfo();
        } else {
            cout << "Customer not found." << endl;
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
