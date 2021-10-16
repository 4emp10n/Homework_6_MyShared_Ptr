#include <iostream>
#include "MyShared_ptr.h"

using namespace std;

int main()
{
    MyShared_ptr<int> ptr (new int(10));
    MyShared_ptr<int> ptr2 (ptr);
    MyShared_ptr<int> ptr3{};
    ptr3 = ptr;
    cout<<*ptr2<<endl;
    return 0;
}