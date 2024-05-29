#include <iostream>
#include <string.h>


class Person {
protected:
    int age;
    char* name;

public:
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
        delete[] name;
    }

    int getAge() const {
        return age;   
    }

    char* getName() const {
        return name;
    }
    
    // Use virtual to indicate that the method to use should be resolved through a vtable at runtime
    virtual void sayHello() {
        std::cout << "Hello from Person" << std::endl;
    }
};


class Student : public Person {
private:
    int numSubjects;
    float* marks;

public:
    Student(int age, const char* name, int numSubjects) : Person(age, name) {
        this->numSubjects = numSubjects;
        this->marks = new float[numSubjects];
    }
    
    Student(const Student& s) : Person(s) {
        this->numSubjects = s.numSubjects;
        this->marks = new float[s.numSubjects];

        for (int i = 0; i < this->numSubjects; i++) {
            this->marks[i] = s.marks[i];
        }
    }

    ~Student() {
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

    virtual void sayHello() {
        std::cout << "Hi from Student" << std::endl;
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
    
    Student* s = new Student(10, "David", 3);
    Person* p = s;

    s->sayHello();
    p->sayHello();

    return 0;
}

