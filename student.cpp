#include "student.h"
#include <iostream>
#include <sstream>

Student::Student() {
    firstName = "";
    lastName = "";
    creditHours = 0;
}

void Student::init(std::string csvLine) {
    std::stringstream ss(csvLine);
    std::string temp;

    std::string street, city, state, zip;
    std::string birthStr, gradStr;

    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, street, ',');
    getline(ss, city, ',');
    getline(ss, state, ',');
    getline(ss, zip, ',');
    getline(ss, birthStr, ',');
    getline(ss, gradStr, ',');
    getline(ss, temp);

    creditHours = std::stoi(temp);

    address.init(street, city, state, zip);
    birthDate.init(birthStr);
    gradDate.init(gradStr);
}

void Student::printStudent() const {
    std::cout << firstName << " "
              << lastName << std::endl;

    address.printAddress();

    std::cout << "DOB: ";
    birthDate.printDate();

    std::cout << "Grad: ";
    gradDate.printDate();

    std::cout << "Credits: "
              << creditHours << std::endl;

    std::cout << "____________________________________"
              << std::endl;
}

std::string Student::getLastFirst() const {
    return lastName + ", " + firstName;
}
