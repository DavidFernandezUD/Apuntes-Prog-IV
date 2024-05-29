#include <iostream>


using namespace std;


namespace fruit {
    
    class Apple {
    public:
        float weight;
        float size;

        Apple() {
            weight = 200;
            size = 7;
        }

        void eat() {
            cout << "Eating apple..." << endl;
        }
    };
}


namespace computer {

    class Apple {
    public:
        unsigned int ram;
        unsigned int cores;
        float prize;

        Apple() {
            ram = 8;
            cores = 4;
            prize = 2000;
        }

        void code() {
            cout << "Just kidding..." << endl;
        }
    };
}


int main() {
    
    fruit::Apple fruitApple;
    computer::Apple computerApple;

    fruitApple.eat();
    computerApple.code();

    return 0;
}

