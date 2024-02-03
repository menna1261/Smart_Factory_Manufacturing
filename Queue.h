#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;
template <class T>
class Queue {
    public:
    int front, rear, capacity;
    T* queue;
    Queue(int c)
    {
        front = rear = 0;
        capacity = c;
        queue = new T[capacity];
    }

    ~Queue() { delete[] queue; }
    friend std::ostream& operator << (std::ostream& out,T& obj){
       obj.print();
       return out;
    }
    void queueEnqueue(T data);
    bool isFull();
    bool isEmpty();
    void queueDequeue();
    // print queue elements
    void queueDisplay();

    // print front of queue
    void queueFront();
};
template<typename T>
void Queue<T>::queueEnqueue(T data)
    {
        // check queue is full or not
        if (capacity == rear) {
            cout<<"Queue is full"<<endl;

        }

        // insert element at the rear
               else {
            queue[rear] = data;
            rear++;
        }

    }


template<typename T>
bool Queue<T>:: isFull(){
    return(rear==capacity);
    }


template<typename T>
bool Queue<T>:: isEmpty(){
      return front==rear;
    }



template<typename T>
void Queue<T>::queueDequeue()
    {
        // if queue is empty
        if (front == rear) {
            cout<<"Queue is  empty"<<endl;

        }

        // shift all the elements from index 2 till rear
        // to the left by one
        else {
            for (int i = 0; i < rear - 1; i++) {
                queue[i] = queue[i + 1];
            }

            // decrement rear
            rear--;
        }

    }



template<typename T>
void Queue<T>::queueDisplay()
    {
        int i;
        if (front == rear) {
           cout<<"Queue is Empty"<<endl;

        }


        else{
        // traverse front to rear and print elements
        for (i = front;i < rear; i++) {
            cout<<"Product no " <<i+1<<endl;
            queue[i].print();}
           cout<<endl;
        }


    }

template<typename T>
void Queue<T>::queueFront()
    {
        if (front == rear) {
          cout<<"Queue is Empty"<<endl;

        }
       cout<<"Front Element is: "<< queue[front];

    }

#endif // QUEUE_H
