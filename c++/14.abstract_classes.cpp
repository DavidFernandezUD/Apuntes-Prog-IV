#include <iostream>


// NOTE: If a class has an unimplemented virtual method (abstract method), it can't be instantiated
class Base {
private:
    float f1;
public:

    // Assign 0 to a virtual function to indicate it is not implemented (abstract)
    // NOTE: You don't have to add virtual to mehods implemented outside class in .h, just in the class definition
    virtual void abstractMethod() = 0;
};


class Derived : public Base {
private:
    float f2;
public:
    virtual void abstractMethod() {
        std::cout << "void Derived::abstractMethod()" << std::endl;
    }
};


int main() {

    Base* base = new Derived();

    base->abstractMethod();
    
    delete base;

    return 0;
}

