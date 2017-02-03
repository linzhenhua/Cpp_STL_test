#include <iostream>
#include <memory>

using namespace std;

/*
//某个函数是数据的终点
void fun1(const auto_ptr<int>& x)    //auto_prt的使用：拥有权的转移
{
    cout << " fun1(): " << *x << endl;
}

//某个函数是数据的起点
auto_ptr<int> fun2()
{
    auto_ptr<int> x(new int);

    *x = 10;

    return x;
}
*/

int main()
{
    auto_ptr<int> p1(new int(20));
    auto_ptr<int> p2 = p1;
    auto_ptr<int> p3(nullptr);

    //*p1 = 10;
    //p2 = auto_ptr<int>(new int);
    //p2 = p1;
    cout << *p2 << endl;

    int *p = p2.get();

    cout << *p << endl;

    *p = 11;

    cout << *p2 << endl;

    p3 = p2;

    //p1 = p2;   error

    if(p1.get() == nullptr)
        cout << "p1 = nullptr" << endl;

    p3.release();
    //cout << *p3 << endl;

    int *p4 = new int(23);
    p3.reset(p4);

    cout << *p3 << endl;

    return 0;
}
