#include <iostream>

class Parent1 {
    int value{999};
public:
    Parent1(){}
    ~Parent1(){}
    void print() {std::cout << "Parent1" << std::endl; }
};

class Parent2 {
    int value{888};
public:
    Parent2(){}
    ~Parent2(){}
    void print() {std::cout << "Parent1" << std::endl; }
};

class Child:public Parent1, public Parent2
{

};

int main()
{
    Child c;
    c.print();
    return 0;
}
