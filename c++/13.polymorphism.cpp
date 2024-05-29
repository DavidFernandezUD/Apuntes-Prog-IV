#include <iostream>


using namespace std;


class Base {
private:
    float f1;
public:
    void nonPolymorphic() {
        cout << "void Base::nonPolymorphic()" << endl;
    }
    
    // Virtual indicates that the address of this function should be resolved through a vtable at runtime instead of comppile time
    virtual void polymorphic() {
        cout << "void Base::polymorphic()" << endl;
    }

    // Use virtual destructors so that the appropriate destructor is called, even when the pointer is of the class of the parent
    virtual ~Base() {
        cout << "Base destructor" << endl;
    }
};


class Derived : public Base {
private:
    float f2;
public:
    void nonPolymorphic() {
        cout << "void Derived::nonPolymorphic()" << endl;
    }

    virtual void polymorphic() {
        cout << "void Derived::polymorphic()" << endl;
    }

    void helper() {
        // You can specify which version of a polymorphic method to use
        Base::polymorphic();
    }
    
    // NOTE: Virtual destructor is only needed in the parent's destructor
    virtual ~Derived() {
        cout << "Derived destructor" << endl;
    }
};


int main() {
    
    // Polymorphic and non-polymorphic methods only differ when working with pointers
    Base* base = new Derived();
    
    // If the method is not polymorphic, the pointer's type implementation is called
    base->nonPolymorphic();

    // If the method is polymorphic, the object's type implementation is called
    base->polymorphic();
    
    Derived* derived = new Derived();
    derived->helper();

    // Althogh base is of type Base*, the ~Derived() constructor will also be called since it is virtual
    delete base;

    return 0;
}

