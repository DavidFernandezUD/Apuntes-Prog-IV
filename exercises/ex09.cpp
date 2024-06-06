#include <iostream>


class Point {
protected:
    int x;
    int y;
public:
    Point(int x, int y) : x(x), y(y) {}

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    virtual void print() {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};


class Point3D : public Point {
private:
    int z;
public:
    Point3D(int x, int y, int z) : Point(x, y), z(z) {}

    void setZ(int z) {
        this->z = z;
    }

    int getZ() {
        return z;
    }

    virtual void print() {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }

    Point3D operator*(const Point3D& p) const {
        Point3D res = *this;
        res.x *= p.x;
        res.y *= p.y;
        res.z *= p.z;

        return res;
    }

    Point3D& operator*(int scalar) {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;

        return *this;
    }
};


int main() {
    
    std::cout << "Point arr[5]" << std::endl;

    Point* arr[5];

    Point p(6, 9);
    arr[0] = &p;
    arr[1] = new Point(2, 3);
    arr[2] = new Point3D(2, 1, 4);
    arr[3] = new Point(6, 8);
    arr[4] = new Point3D(5, 3, -2);

    for (int i = 0; i < 5; i++) {
        arr[i]->print();
    }
    
    std::cout << "c = a + b" << std::endl;

    Point3D a(1, 3, -2);
    Point3D b(3, -1, 4);
    Point3D c = a * b;

    a.print();
    b.print();
    c.print();

    std::cout << "c = c * 2" << std::endl;

    c = c * 2;

    c.print();

    return 0;
}

