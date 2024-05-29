#include <iostream>


class Date {

private:

    unsigned int year;
    unsigned int month;
    unsigned int day;

    char* note;

public:
    
    // Default constructor called when instantiating an object without arguments
    Date() {
        this->year = 2024;
        this->month = 5;
        this->day = 15;

        this->note = new char[10];
    }

    ~Date() {
        std::cout << "Deleting..." << std::endl;
        delete[] this->note;
    }
    
    int getYear() {
        return this->year;
    }

    int getMonth() {
        return this->month;
    }

    int getDay() {
        return this->day;
    }
};


int main() {
    
    // The destructore deletes the object's dinamic memory when it gets out of scope
    {
        // NOTE: No need to pass arguments to default constructor
        Date obj;

        std::cout << "Date: " << obj.getDay() << "/" << obj.getMonth() << "/" << obj.getYear() << std::endl;
    }

    std::cout << "Hello from outside!" << std::endl;

    return 0;
}

