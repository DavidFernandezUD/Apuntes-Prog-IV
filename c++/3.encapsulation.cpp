#include <iostream>


class Date {

private:

    unsigned int year;
    unsigned int month;
    unsigned int day;

public:
    
    void setYear(unsigned int year) {
        this->year = year;
    }

    void setMonth(unsigned int month) {
        this->month = month;
    }

    void setDay(unsigned int day) {
        this->day = day;
    }

    unsigned int getYear() {
        return this->year;
    }

    unsigned int getMonth() {
        return this->month;
    }

    unsigned int getDay() {
        return this->day;
    }

    bool isLeapYear() {
        return (this->year % 4 == 0) && (this->year % 100 != 0) | (this->year % 400 == 0);
    }

};


int main() {

    Date obj;
    obj.setYear(2024);
    obj.setMonth(5);
    obj.setDay(15);

    std::cout << "Date: " << obj.getDay() << "-" << obj.getMonth() << "-" << obj.getYear() << std::endl;

    return 0;
}

