#include <iostream>


namespace containers {
    
    class ArrayInt {
        
    private:
        unsigned int capacity;
        int* array;

    public:
        ArrayInt() {
            capacity = 0;
            array = nullptr;
        }

        ArrayInt(unsigned int capacity) {
            this->capacity = capacity;
            this->array = new int[capacity];
        }

        ~ArrayInt() {
            delete[] this->array;
            std::cout << "Array deleted" << std::endl;
        }

        void setValue(unsigned int index, int data) {
            if (index < this->capacity) {
                this->array[index] = data;
            } else {
                std::cerr << "Index out of bounds" << std::endl;
            }
        }

        int getValue(unsigned int index) {
            if (index < this->capacity) {
                return this->array[index];
            } else {
                std::cerr << "Index out of bounds" << std::endl;
                return -1;
            }
        }

        void setCapacity(unsigned int capacity) {
            int* newArray = new int[capacity];
            
            if (capacity >= this->capacity) {
                for (int i = 0; i < this->capacity; i++) {
                    newArray[i] = this->array[i];
                }
            } else {
                for (int i = 0; i < capacity; i++) {
                    newArray[i] = this->array[i];
                }
            }
            delete[] this->array;
            
            this->capacity = capacity;
            this->array = newArray;
        }

        unsigned int getCapacity() {
            return this->capacity;
        }
    };
}


using namespace containers;


int main() {

    ArrayInt arr(8);

    std::cout << "arr->capacity = " << arr.getCapacity() << std::endl;

    arr.setValue(0, 1);
    arr.setValue(1, 2);
    arr.setValue(2, 3);
    arr.setValue(3, 4);
    arr.setValue(4, 5);
    arr.setValue(5, 6);
    arr.setValue(6, 7);
    arr.setValue(7, 8);

    std::cout << "[";
    for (int i = 0; i < arr.getCapacity(); i++) {
        std::cout << " " << arr.getValue(i);
    }
    std::cout << " ]\n\n";

    arr.setCapacity(10);

    std::cout << "arr->capacity = " << arr.getCapacity() << std::endl;

    arr.setValue(8, 9);
    arr.setValue(9, 10);

    std::cout << "[";
    for (int i = 0; i < arr.getCapacity(); i++) {
        std::cout << " " << arr.getValue(i);
    }
    std::cout << " ]" << std::endl;

    return 0;
}

