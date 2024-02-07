#ifndef STACK__H
#define STACK__H
#include<iostream>
#include<cassert>
using namespace std;
template<class T>
class stack_ {
private:
    int size = 10;
    int top;
     T* array;
public:
    stack_() :top(-1) {
        array = new T[10];
    }
   // stack_(){}
    int isFull() ;
    int isEmpty();
    // we display the elements of the array reversely (first in last out)
    void display();
    void push(T x) ;
    T pop() ;
    T peek() ;

};
template<class T>
void stack_<T>::display(){
for (int i = 0; i < top; i++) {
            cout << array[i] << "->";
        }
        cout<<array[top];
}
template<class T>
void stack_<T>::push(T x) {
        assert(!isFull());
        array[++top] = x;
    }


template<class T>
T stack_<T>::pop() {
        assert(!isEmpty());
        return array[top--];
    }



template<class T>
T stack_<T>::peek() {
        assert(!isEmpty());
        return array[top];
    }



template<class T>
int stack_<T>:: isFull() {
        return top == size - 1;
    }



template<class T>
int stack_<T>::isEmpty() {
        return top == -1;
    }

#endif // STACK__H
