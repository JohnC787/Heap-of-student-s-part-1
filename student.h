#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "address.h"
#include "date.h"

class Student {
private:
    std::string firstName;
    std::string lastName;
    int creditHours;

    Address* address;
    Date* dob;
    Date* gradDate;

public:
    Student();
    Student(std::string csvLine);
    ~Student();

    std::string getFirstName();
    std::string getLastName();
    int getCredits();

    void printSummary();
    void printDetails();
};

#endif
