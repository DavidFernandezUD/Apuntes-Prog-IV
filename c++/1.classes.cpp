#include <iostream>


class Date {

    unsigned int year = 2024;
    unsigned int month = 5;
    unsigned int day = 5;

public:

    unsigned int getYear() {
        return year;
    }

    unsigned int getMonth() {
        return month;
    }

    unsigned int getDay() {
        return day;
    }

};


int main() {

    Date obj;

    std::cout << "Date: " << obj.getDay() << "/" << obj.getMonth() << "/" << obj.getYear() << std::endl;

    return 0;
}

