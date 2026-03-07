#include "student.h"
#include <iostream>
#include <sstream>
#include <vector>

Student::Student() {
    address = new Address();
    dob = new Date();
    gradDate = new Date();
}

Student::Student(std::string line) {

    std::stringstream ss(line);
    std::string token;

    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, token, ',');
    creditHours = stoi(token);

    address = new Address(line);
    dob = new Date(line);
    gradDate = new Date(line);
}

Student::~Student() {
    delete address;
    delete dob;
    delete gradDate;
}

std::string Student::getFirstName() { return firstName; }
std::string Student::getLastName() { return lastName; }
int Student::getCredits() { return creditHours; }

void Student::printSummary() {
    std::cout << lastName << ", " << firstName << std::endl;
}

void Student::printDetails() {

    std::cout << firstName << " " << lastName << std::endl;

    address->print();

    std::cout << "DOB: ";
    dob->print();

    std::cout << "Grad: ";
    gradDate->print();

    std::cout << "Credits: " << creditHours << std::endl;
    std::cout << "____________________________________" << std::endl;
}
