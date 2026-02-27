#include "date.h"
#include <iostream>
#include <sstream>

Date::Date() {
    month = 0;
    day = 0;
    year = 0;
}

void Date::init(std::string dateStr) {
    std::stringstream ss(dateStr);
    std::string temp;

    getline(ss, temp, '/');
    month = std::stoi(temp);

    getline(ss, temp, '/');
    day = std::stoi(temp);

    getline(ss, temp);
    year = std::stoi(temp);
}

void Date::printDate() const {
    std::string months[] = {"",
        "January","February","March","April","May","June",
        "July","August","September","October","November","December"
    };

    std::cout << months[month] << " "
              << day << ", "
              << year << std::endl;
}
