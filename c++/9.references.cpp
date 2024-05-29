#include <iostream>
#include <string.h>


class String {
private:
    char* string;

public:
    String() {
        string = new char[1];
        string[0] = '\0';
    }

    String(const char* string) {
        this->string = new char[strlen(string) + 1];
        strcpy(this->string, string);
    }

    ~String() {
        delete[] string;
    }
    
    // NOTE: If you don't pass by reference here, the str object will be deleted after exiting the function scope
    bool isEqual(String &str) {
        return strcmp(string, str.string) == 0;
    }

    void print() {
        std::cout << string << std::endl;
    }
};


int main() {

    String str1("String 1");
    String str2("String 2");

    str1.print();
    str2.print();
    
    std::cout << (str1.isEqual(str2) ? "Equal" : "Not equal") << std::endl;

    str1.print();
    str2.print();

    return 0;
}

