#include "product.h"
product::product(){
}
void product:: Enter_operations(){
    getline(cin,name);
        cout<<"Enter product's name : "<<endl;
        //cin>>name;
        getline(cin,name);
        int x ;
        cout<<"Enter the number of manufacturing steps : "<<endl;
        cin>>x;
       // assert(x<=10);
        int counter = 1;
        string y;
         getline(cin,y);
     while( counter <=x){
        string op;

        cout<<"Enter step number "<<counter <<" : "<<endl;
        getline(cin,op);
        operations.push(op);
        counter++;
     }

    }
 void product::  print(){
    cout<<"---------------------------------"<<endl;
     cout<<"\nProduct's name : "<<name<<endl;
     cout<<"The sequence of manufacturing steps : ";
      operations.display();
      cout<<"\n---------------------------------"<<endl;

    }
