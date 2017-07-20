#include <iostream>
#include <string>

using namespace std;

void test()
{
    const int a = 100;

    int *p = const_cast<int *>(&a);

    *p = 10;       //企图修改a的值 会导致未定义行为

    cout << "*p = " << *p << "\na = " << a << endl;
    //输出：
    //*p = 10
    //a = 100            a的值依旧不能改变

    cout << "&a = " << &a << "\np = " << p << endl;
     //输出：
     //&a = 0x28ff08
     //p = 0x28ff08
}

int main()
{
    test();

    return 0;
}
