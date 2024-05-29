#include <iostream>


class Base {

// Protected members are accessible within the class and it's derived classes
protected:
    float f1;

public:
    Base() : f1(0) {
        std::cout << "Base::Base()" << std::endl;
    }

    Base(float f1) : f1(f1) {
        std::cout << "Base::Base(" << f1 << ")" << std::endl;
    }

    float getF1() {
        return f1;
    }

    void setF1(float f1) {
        this->f1 = f1;
    }
};


class Derived : public Base {
private:
    float f2;

public:
    Derived() : Base(), f2(0) {
        std::cout << "Derived::Derived()" << std::endl;
    }

    // NOTE: Fore some reason you can't use f1(f1) on the derived class initialization list
    Derived(float f1, float f2) : Base(f1), f2(f2) {
        std::cout << "Base::Base(" << f1 << ")" << std::endl;
    }

    float getF2() {
        return f2;
    }

    void setF2(float f2) {
        this->f2 = f2;
    }
};


int main() {
    
    std::cout << "sizeof(Base) = " << sizeof(Base) << std::endl;
    std::cout << "sizeof(Derived) = " << sizeof(Derived) << std::endl;
    
    // Two objects are created when instantiating a derived class
    Derived obj(1, 2);

    // We can address any of those with dynamic linking
    Base* base = &obj;
    Derived* derived = &obj;
    
    // NOTE: Changes made to any of the references affect the other
    base->setF1(3);

    std::cout << "base.f1 = " << base->getF1() << std::endl;
    std::cout << "derived.f1 = " << derived->getF1() << std::endl;
    std::cout << "derived.f2 = " << derived->getF2() << std::endl;
    
    // You can create a general class array
    Base* arr[2];
    arr[0] = new Base();
    arr[1] = new Derived();

    return 0;
}

