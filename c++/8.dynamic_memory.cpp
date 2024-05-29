#include <iostream>


class Point {
public:
    int x, y;

    Point() {
        x = 1;
        y = 1;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};


int main() {

    int* pInt1 = new int;
    int* pInt2 = new int(4);            // Initialize primitive with a value
    int* pInt3 = new int{3};            // This way it doesn't convert type implicitly

    Point* pPoint1 = new Point;         // Default constructor
    Point* pPoint2 = new Point();       // Also default constructor
    Point* pPoint3 = new Point(9, 8);   // Parametric constructor

    int* intArray = new int[8];         // Reserve multiple slots for objects

    std::cout << "pInt1 = " << *pInt1 << std::endl;
    std::cout << "pInt2 = " << *pInt2 << std::endl;
    std::cout << "pInt3 = " << *pInt3 << std::endl;

    std::cout << "pPoint1 = (" << pPoint1->x << ", " << pPoint1->y << ")" << std::endl;
    std::cout << "pPoint2 = (" << pPoint2->x << ", " << pPoint2->y << ")" << std::endl;
    std::cout << "pPoint3 = (" << pPoint3->x << ", " << pPoint3->y << ")" << std::endl;
    
    std::cout << "[";
    for (int i = 0; i < 8; i++) {
        std::cout << " " << intArray[i];
    }
    std::cout << " ]" << std::endl;

    // Free memory
    delete pInt1;
    delete pInt2;
    delete pInt3;
    delete pPoint1;
    delete pPoint2;
    delete pPoint3;
    
    // Free arrays
    delete[] intArray;

    return 0;
}

