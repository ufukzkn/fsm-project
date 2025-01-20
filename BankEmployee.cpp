#include "BankEmployee.hpp"

using namespace std;

BankEmployee::BankEmployee(const string& name, int age, const string& position)
    : Person(name, age), position(position) {}

void BankEmployee::displayInfo() const {
    Person::displayInfo();
    cout << "Position: " << position << endl;
}
