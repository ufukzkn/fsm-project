#ifndef BANKEMPLOYEE_HPP
#define BANKEMPLOYEE_HPP

#include "Person.hpp"

using namespace std;

class BankEmployee : public Person {
private:
    string position;

public:
    BankEmployee(const string& name, int age, const string& position);
    void displayInfo() const override;
};

#endif
