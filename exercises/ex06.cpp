#include <iostream>
#include <string.h>


class Person {
protected:
    int age;
    char* name;

public:

    // NOTE: It will throw a warning if you try to pass a string literal as a non-const char*
    Person(int age, const char* name) : age(age) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Person(const Person& p) {
        this->age = p.age;
        this->name = new char[strlen(p.name) + 1];
        strcpy(this->name, p.name);
    }

    ~Person() {
        // REMEMBER: A string is a char array
        delete[] name;
    }

    int getAge() const {
        return age;   
    }

    char* getName() const {
        return name;
    }
};


class Student : public Person {
private:
    int numSubjects;
    
    // NOTE: You have to declare array as pointer if you don't know it's size
    float* marks;

public:
    Student(int age, const char* name, int numSubjects) : Person(age, name) {
        this->numSubjects = numSubjects;
        this->marks = new float[numSubjects];
    }
    
    // NOTE: You can call the copy constructor of a base class with a child class argument
    Student(const Student& s) : Person(s) {
        this->numSubjects = s.numSubjects;
        this->marks = new float[s.numSubjects];

        for (int i = 0; i < this->numSubjects; i++) {
            this->marks[i] = s.marks[i];
        }
    }

    ~Student() {
        // NOTE: Base class destructor is automatically called after child's destructor
        delete[] marks;
    }

    int getNumSubjects() const {
        return numSubjects;
    }

    void setMark(int index, float mark) {
        this->marks[index] = mark;
    }

    float getMark(int index) const {
        return this->marks[index];
    }
};


void printMarks(const Student& s) {
    std::cout << "Marks:" << std::endl;
    for (int i = 0; i < s.getNumSubjects(); i++) {
        std::cout << "  [" << i << "] = " << s.getMark(i) << std::endl;
    }
}


void printPerson(const Person& p) {
    std::cout << "Person(age=" << p.getAge() << ", name=" << p.getName() << ")" << std::endl;
}


int main() {

    Student s(19, "David", 4);
    s.setMark(0, 7.2f);
    s.setMark(1, 5.4f);
    s.setMark(2, 9.8f);
    s.setMark(3, 6.5f);

    Person p(87, "Carlos");

    printPerson(p);

    printPerson(s);
    printMarks(s);

    return 0;
}

