#include <iostream>


class Date {

public:
    static const unsigned int month;
    static bool isLeapYear(unsigned int year);
};


const unsigned int Date::month = 12;

bool Date::isLeapYear(unsigned int year) {
    return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}


int main() {

    std::cout << "Date::month = " << Date::month << std::endl;
    std::cout << "Is 2006 a leap year? " << (Date::isLeapYear(2006) ? "Yes" : "No") << std::endl;

    return 0;
}

