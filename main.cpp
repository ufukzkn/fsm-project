// Bank Management System in C++

#include <iostream>
#include "BankSystem.hpp"

using namespace std;

int main() {
    BankSystem bank;

    // Adding customers
    bank.addCustomer("Ricardo Quaresma", 30, 1001, 5000.0);
    bank.addCustomer("Rafa Silva", 28, 1002, 3000.0);
    bank.addCustomer("Cristiano Ronaldo", 38, 1003, 10000.0);
    bank.addCustomer("Pepe", 40, 1004, 8000.0);
    bank.addCustomer("Bernardo Silva", 29, 1005, 6000.0);

    // Adding employees
    bank.addEmployee("Atiba Hutchinson", 35, "Manager");
    bank.addEmployee("Mario Gomez", 40, "Clerk");
    bank.addEmployee("Manuel Neuer", 37, "Security");
    bank.addEmployee("Necip Uysal", 34, "Assistant Manager");

    // Display customers and employees
    cout << "\nBank Customers:\n";
    bank.displayCustomers();

    cout << "\nBank Employees:\n";
    bank.displayEmployees();

    // Perform transactions
    try {
        Customer* customer = bank.findCustomer(1001);
        if (customer) {
            customer->deposit(2000.0);
            cout << "Trying depositing 2000\n";
            cout << "\nUpdated Info for Customer 1001:\n";
            customer->displayInfo();
            customer->withdraw(1000.0);
            cout << "Trying withdrawing 1000\n";
            cout << "Updated Info for Customer 1001:\n";
            customer->displayInfo();
        } else {
            cout << "Customer not found." << endl;
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    int onlyfornutshuttingdownimmediately;//for windows, when I run the .exe itself, it shuts down right away 
    cin >>onlyfornutshuttingdownimmediately;//soo, I think it explain itselfs

    return 0;
}
