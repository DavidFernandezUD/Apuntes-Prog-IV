#include <iostream>


class Point {
private:
    float x, y;

public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void add1(Point p) {
        this->x += p.x;
        this->y += p.y;
    }

    void add2(Point& p) {
        this->x += p.x;
        this->y += p.y;
    }

    void add3(Point* p) {
        this->x += p->x;
        this->y += p->y;
    }

    Point getAdd(Point& p) {
        return Point(
            this->x + p.x,
            this->y + p.y
        );
    }

    void swap1(Point p) {
        int tempX = x;
        int tempY = y;
        this->x = p.x;
        this->y = p.y;
        p.x = tempX;
        p.y = tempY;
    }

    void swap2(Point& p) {
        int tempX = x;
        int tempY = y;
        this->x = p.x;
        this->y = p.y;
        p.x = tempX;
        p.y = tempY;
    }

    void swap3(Point* p) {
        int tempX = x;
        int tempY = y;
        this->x = p->x;
        this->y = p->y;
        p.x = tempX;
        p.y = tempY;
    }

    void print() {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }

};


int main() {

    Point a(1, 2);
    Point b(-3, 1);
    
    std::cout << "--------------VALUE--------------" << std::endl;

    a.add1(b);

    a.print();
    b.print();

    std::cout << "------------REFERENCE------------" << std::endl;

    a.add2(b);

    a.print();
    b.print();

    std::cout << "------------POINTER------------" << std::endl;

    a.add3(&b);

    a.print();
    b.print();

    return 0;
}

