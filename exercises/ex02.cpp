#include <iostream>


namespace containers {

    class Element {
    private:
        int data;
        Element* next;

    public:
        Element(int data) {
            this->data = data;
            this->next = nullptr;
        }

        int getData() {
            return this->data;
        }

        void setNext(Element* next) {
            this->next = next;
        }
        
        // NOTE: const indicates that the method does not change any member variables of the object
        Element* getNext() const {
            return this->next;
        }
    };
    

    class Stack {
    private:
        Element* first;
        unsigned int size;

    public:
        Stack() {
            first = nullptr;
            size = 0;
        }

        ~Stack() {
            clear();
        }

        void push(int data) {
            Element* newElement = new Element(data);
            newElement->setNext(first);
            first = newElement;
            size++;
        }

        int pop() {
            if (first != nullptr) {
                Element* topElement = first;
                int data = topElement->getData();
                first = first->getNext();
                
                delete topElement;
                size--;

                return data;
            } else {
                throw std::out_of_range("Stack is empty");
            }
        }

        int poll() {
            if (first != nullptr) {
                return first->getData();
            } else {
                throw std::out_of_range("Stack is empty");
            }
        }

        void clear() {
        
            std::cout << "Clearing" << std::endl;

            while (first != nullptr) {
                Element* toDelete = first;
                first = first->getNext();
                delete toDelete;
            }
            size = 0;
        }

        int getSize() {
            return size;
        }
    };
}


using namespace containers;


int main() {

    Stack stack;

    for (int i = 0; i < 10; i++) {
        stack.push(10 - i);
    }

    std::cout << "Stack size = " << stack.getSize() << std::endl;

    std::cout << "[";
    while (stack.getSize() > 0) {
        std::cout << " " << stack.pop();
    }
    std::cout << " ]" << std::endl;

    return 0;
}

