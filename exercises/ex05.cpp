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
    
    std::cout << "---- Parametric cosntructor ----" << std::endl;
    Student a("David");             // Parametric cosntructor call
    std::cout << "\n\n";

    std::cout << "---- Pass by reference ----" << std::endl;
    printStudentRef(a);             // No copy nor copy constructor call
    std::cout << "\n\n";

    std::cout << "---- Pass by value ----" << std::endl;
    printStudent(a);                // Copy constructor call
    std::cout << "\n\n";

    std::cout << "---- Declaration and assignation ----" << std::endl;
    Student b = a;                  // Copy constructor call
    std::cout << "\n\n";

    std::cout << "---- Explicit copy constructor call ----" << std::endl;
    Student c(b);                   // Copy constructor call
    std::cout << "\n\n";

    std::cout << "---- Pass by pointer ----" << std::endl;
    printStudentPtr(&c);            // No copy constructor call
    std::cout << "\n\n";

    std::cout << "---- copy allocation with new ----" << std::endl;
    Student* d = new Student(c);    // Copy constructor call
    std::cout << "\n\n";

    std::cout << "---- Manual deletion ----" << std::endl;
    delete d;                       // Destructor call
    std::cout << "\n\n";

    std::cout << "Automatic deletion of no dinamic variables" << std::endl;
    return 0;
}

