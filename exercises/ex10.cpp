#include <iostream>


class Point3D {
private:
    int x;
    int y;
    int z;
public:
    Point3D(int x, int y, int z) : x(x), y(y), z(z) {}

    Point3D operator+(const Point3D& p) const {
        Point3D res(x + p.x, y + p.y, z + p.z);
        return res;
    }
    
    Point3D& operator+=(const Point3D& p) {
        this->x += p.x;
        this->y += p.y;
        this->z += p.z;

        return *this;
    }

    int operator*(const Point3D& p) const {
        return x * p.x + y * p.y + z * p.z;
    }

    Point3D operator*(int scalar) const {
        Point3D res(x * scalar, y * scalar, z * scalar);
        return res;
    }

    friend std::istream& operator>>(std::istream& in, Point3D& p);

    friend std::ostream& operator<<(std::ostream& out, const Point3D& p);
};


std::istream& operator>>(std::istream& in, Point3D& p) {
    std::cout << "x = ";
    std::cin >> p.x;
    std::cout << "y = ";
    std::cin >> p.y;
    std::cout << "z = ";
    std::cin >> p.z;

    return in;
}

std::ostream& operator<<(std::ostream& out, const Point3D& p) {
    // REMEMBER: You can't access the member variables directly, you have to take them from "p"
    out << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return out;
}


int main() {
    
    Point3D a(2, 4, 1);
    Point3D b(3, -1, 6);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    std::cout << "a + b => " << a + b << std::endl;

    a += b;
    std::cout << "a += b => " << a << std::endl;

    int dot = a * b;
    std::cout << "a * b => " << dot << std::endl;
    
    a = a * 2;
    std::cout << "a * 2 => " << a << std::endl;

    std::cin >> a;
    std::cout << a << std::endl;

    return 0;
}

