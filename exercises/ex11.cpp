#include <iostream>
#include <string.h>


class Student {
private:
    static int counter;
    int id;
    char* name;

public:
    Student(const char* name) {
        
        std::cout << "In Student constructor" << std::endl;

        this->id = counter++;

        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Student(const Student& a) {
        
        std::cout << "In Student copy constructor" << std::endl;

        this->id = a.id;
        this->name = new char[strlen(a.name) + 1];
        strcpy(this->name, a.name);
    }

    ~Student() {
    
        std::cout << "In Student destructor" << std::endl;

        delete[] name;
    }

    int getId() {
        return id;
    }

    char* getName() {
        return name;
    }

    Student& operator=(const Student& s) {

        std::cout << "In Student assignment copy" << std::endl;
    
        // Important to free the dinamic memory of the initialized object before copying new data
        // NOTE: Esta se le colo a Iker
        delete[] this->name;

        this->id = s.id;
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);

        return *this;
    }
};


int Student::counter = 0;


void printStudent(Student student) {
    std::cout << "* Student" << std::endl;
    std::cout << "\t*ID: " << student.getId() << std::endl;
    std::cout << "\t*Name: " << student.getName() << std::endl;
}

void printStudentRef(Student& student) {
    std::cout << "* Student" << std::endl;
    std::cout << "\t*ID: " << student.getId() << std::endl;
    std::cout << "\t*Name: " << student.getName() << std::endl;
}

void printStudentPtr(Student* student) {
    std::cout << "* Student" << std::endl;
    std::cout << "\t*ID: " << student->getId() << std::endl;
    std::cout << "\t*Name: " << student->getName() << std::endl;
}


int main() {

    Student a("Juan");
    Student b("David");

    b = a;

    return 0;
}

