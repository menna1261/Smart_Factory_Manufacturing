#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include<stack_.h>
using namespace std;
class product{

    stack_<string>operations;
    string name;

public:
    product();
    void Enter_operations();
    void print();
};

#endif // PRODUCT_H
