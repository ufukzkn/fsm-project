#include "Person.hpp"

using namespace std;

Person::Person(const string& name, int age) : name(name), age(age) {}

Person::~Person() {}

void Person::displayInfo() const {
    cout << "Name: " << name << ", Age: " << age << endl;
}
