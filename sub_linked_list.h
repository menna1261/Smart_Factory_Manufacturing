#ifndef SUB_LINKED_LIST_H
#define SUB_LINKED_LIST_H
#include<iostream>
#include<Queue.h>
using namespace std;
template <class T>
struct Node{
    Queue<T>* data;
    Node <T>* next;

    Node(){
        data=new Queue<T>(4);
        next=nullptr;
  }
};
template <class T>
class sub_linked_list{
 Node<T>* head;
 Node<T>* tail;
 public:
     sub_linked_list():head(nullptr),tail(nullptr){}
     void insert(T x);
     void pop();
     Node<T>* resize();
     void print();


};
template<class T>
void sub_linked_list<T>::pop(){
     if(!head){
        cout<<"The list is empty"<<endl;
        return;
     }
     if(!head->data->isEmpty()){
        head->data->queueDequeue();
        cout<<"First product in the list is deleted successfully " <<endl;
     }
     else if(head->data->isEmpty()){
        Node<T>*temp = head;
        head=head->next;
        delete temp;
        cout<<"First sub linked list is deleted"<<endl;
     }


}
template<class T>
void sub_linked_list<T>::insert(T x){
      if(!head){
            Node<T>*newnode=new Node<T>();
            newnode->data->queueEnqueue(x);
            head=newnode;
            head->next=nullptr;
            //
            tail = newnode;
            tail->next=nullptr;
      }
      else{
            if(tail->data->isFull()){
                Node<T>*temp = resize();
                temp->data->queueEnqueue(x);
                tail->next = temp;
                tail = tail->next;

            }

            else{
                tail->data->queueEnqueue(x);
            }


      }
      cout<<"Product inserted successfully"<<endl;


     }
template<class T>
Node<T>* sub_linked_list<T>::resize(){
         Node<T>*newnode=new Node<T>();
         /*il ->next = newnode;
         tail = newnode;*/
         return newnode;
     }
template<class T>
void sub_linked_list<T>::print(){
   if(!head)
    cout<<"Empty"<<endl;
    int counter = 0;
     for(Node<T>*cur = head ;cur;cur=cur->next,counter++){
           // for(int i =0 ;i<;i++){
        cur->data->queueDisplay();
     }
}
#endif // SUB_LINKED_LIST_H
