#include <iostream>


class Point {
private:
    float x, y;

public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void setX(float x) {
        this->x = x;
        this->y = y;
    }

    void setY(float y) {
        this->x = x;
        this->y = y;
    }

    float getX() const {
        return this->x;
    }

    float getY() const {
        return this->y;
    }

    void add(const Point& p) {
        this->x += p.x;
        this->y += p.y;
    }
};


int main() {

    const Point obj(2, 3);

    std::cout << "Point(" << obj.getX() << ", " << obj.getY() << ")" << std::endl;

    return 0;
}

