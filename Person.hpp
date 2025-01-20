#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <iostream>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(const string& name, int age);
    virtual ~Person();
    virtual void displayInfo() const;
};

#endif
