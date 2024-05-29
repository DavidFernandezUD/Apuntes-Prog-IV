#include <iostream>


class Student {
private:
    int id;
    int numMarks;
    int* marks;

public:
    Student(const int id, const int numMarks) {
        this->id = id;
        this->numMarks = numMarks;
        this->marks = new int[numMarks];
    }

    // Copy constructor
    Student(const Student& a) {
        this->id = a.id;
        this->numMarks = a.numMarks;
        this->marks = new int[a.numMarks];
        for (int i = 0; i < a.numMarks; i++) {
            this->marks[i] = a.marks[i];
        }
    }

    void setMark(int index, int mark) {
        marks[index] = mark;
    }

    int getMark(int index) {
        return marks[index];
    }

    ~Student() {
        delete[] marks;
    }

    void print() const {
        std::cout << "Student( ";
        for (int i = 0; i < numMarks; i++) {
            std::cout << marks[i] << " ";
        }
        std::cout << ")" << std::endl;
    }
};


int main() {

    Student a(1, 5);
    a.setMark(0, 2);
    a.setMark(1, 4);

    // Copy constructor can be called explicitly like any other method
    Student c(a);

    // Copy constructor is called implicitly when using asignment operator on a just initialized object
    Student b = a;

    // Copy constructor is also called when passing an object by value to a function or returning an object

    a.print();
    b.print();

    std::cout << "---------------------------------" << std::endl;

    a.setMark(0, 1);
    a.setMark(1, 2);

    a.print();
    b.print();

    return 0;
}

