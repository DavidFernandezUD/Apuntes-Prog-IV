#include <iostream>


class A {
private:
    int a;
    int b;

public:
    A(int a, int b) {
        this->a = a;
        this->b = b;
    }
    
    // A const method doesn't modify the state of the object
    // NOTE: You can only call const methods on a const object
    void print() const {
        std::cout << "(" << a << ", " << b << ")" << std::endl;
    }
};


int main() {
    
    // Constant variables can't be modified after initialization
    const int a = 3;
    
    // This is a non-constant pointer to a constant integer
    const int* b = new int(2);

    // This is a constant pointer to a non-constant integer
    int* const c = new int(-4);

    // This is a constant pointer to a constant integer
    const int* const d = new int(9);

    // This is a reference to a constant integer
    const int& e = a;

    std::cout << "           const a = " <<  a << ";" << std::endl;
    std::cout << "      const int* b = " << *b << ";" << std::endl;
    std::cout << "      int* const c = " << *c << ";" << std::endl;
    std::cout << "const int* const d = " << *d << ";" << std::endl;
    std::cout << "      const int& e = " <<  e << ";" << std::endl;

    const A obj(1, 2);
    obj.print();

    return 0;
}

