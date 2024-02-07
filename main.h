#include<iostream>
#include<cassert>
#include <cstdlib>          // cls
#include <windows.h>        // Sleep
#include <cstring>          // string, to_string
#include <bits/stdc++.h>    // stringstream
#include <windows.h>        // Sleep
#include<unistd.h>
#include<product.h>
#include<sub_linked_list.h>
using namespace std;
HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);

/** ASSISTANT INLINE FUNCTIONS **/

 //product p;
   sub_linked_list<product> s;
inline void wait_or_clear(unsigned int sec, bool clear_screen = false)
{
    Sleep(sec*1000);
    if (clear_screen) system("cls");
}

inline void printline(string msg, bool end_line = true, int color_code=15)
{
    SetConsoleTextAttribute(cout_handle, color_code);
    cout <<  msg << (end_line?"\n":"\t");
}

inline void print_try_again()
{
    printline("\n\n\n\aInvalid Choice Try Again!!!!!!!!",1,2);
    wait_or_clear(3, 1);
}



int get_menu_choise(string menu, int level = 0)
{
    stringstream X(menu);
    string line, padding;
    int i = 1;
    for(int p=0; p<level+1; ++p)
        padding +="\t";

    while (getline(X, line, ','))
        printline(padding + to_string(i++) + ". " + line,1,level+3);

    printline(level?padding+"0. RETURN BACK":padding+"0. EXIT APP",1,4);
    int c;
    printline("ENTER YOUR CHOICE :",false,15);
    cin >> c;
 return c;
}
int main()
{

    printline("START APPLICATION ....",1,11);
    wait_or_clear(1,1);
    int d = -1;
    while (d!=0)
    {
        wait_or_clear(0,1);
        printline("\n\nMAIN MENU ....",1,15);
        d = get_menu_choise("ADD A PRODUCT,DELETE A PRODUCT,DISPLAY PRODUCTS",0);
        switch(d)
        {
        case 1:
        {


           system("cls");
            printline("\n\nMAIN MENU -> ADD A Product ....");
            product p ;
            p.Enter_operations();
            s.insert(p);
            wait_or_clear(1,1);
        }
        break;
        case 2:{
           cout<<"Popping a product from the front " <<endl;
           s.pop();
           sleep(2);
           wait_or_clear(1,1);

        }
        break;
        case 3:
        {
          s.print();
          sleep(2);
          wait_or_clear(1,1);


        }
        break;

        case 0:
        {
            printline("\n\n\a\t\t\tGoodbye :)......\n\n\n\n\n\n",1,112);
            break;
        default:
            wait_or_clear(3, true);
        }
    }
    }

    return 0;
}

