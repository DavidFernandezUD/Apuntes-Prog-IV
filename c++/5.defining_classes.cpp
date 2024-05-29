#include <iostream>
#include "5.defining_classes.h"


Date::Date() {
    this->year = 2024;
    this->month = 5;
    this->day = 15;
}

void Date::setYear(unsigned int year) {
    this->year = year;
}

void Date::setMonth(unsigned int month) {
    this->month = month;
}

void Date::setDay(unsigned int day) {
    this->day = day;
}


unsigned int Date::getYear() {
    return year;
}

unsigned int Date::getMonth() {
    return month;
}

unsigned int Date::getDay() {
    return day;
}


int main() {
    
    Date obj;

    obj.setYear(2044);
    obj.setMonth(2);

    std::cout << "Date: " << obj.getDay() << "/" << obj.getMonth() << "/" << obj.getYear() << std::endl;

    return 0;
}

