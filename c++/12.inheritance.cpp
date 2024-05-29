#include <iostream>


class Base {
private:
    float f1;

public:
    Base() {
        std::cout << "Base::Base()" << std::endl;
    }
};


class Derived : public Base {
private:
    float f2;

public:
    Derived() {
        std::cout << "Derived::Derived()" << std::endl;
    }
};


int main() {
    
    std::cout << "sizeof(Base) = " << sizeof(Base) << std::endl;
    std::cout << "sizeof(Derived) = " << sizeof(Derived) << std::endl;

    return 0;
}

