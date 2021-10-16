#include <iostream>
#include "MyShared_ptr.h"

using namespace std;

int main()
{
    MyShared_ptr<int> ptr (new int(10));
    MyShared_ptr<int> ptr2 (ptr);

    cout<<*ptr<<endl;
    return 0;
}