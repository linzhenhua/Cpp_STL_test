/*
#include <iostream>
#include <algorithm>

using namespace std;

bool comp1(int x, int y)
{
    return x > y;
}

bool comp2(int x, int y)
{
    return x < y;
}

int main()
{
    int x = 10;
    int y = 11;

    if( max(x, y, comp1) )
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "2" << endl;
    }

    return 0;
}
*/

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class MyTest{
public:
    MyTest(const int& x):m_iNum(x){}

    ~MyTest(){}

    MyTest(const MyTest& rhs)
    {
        m_iNum = rhs.m_iNum;
    }

    MyTest& operator=(const MyTest& rhs)
    {
        m_iNum = rhs.m_iNum;

        return *this;
    }

    bool operator==(const MyTest& rhs) const
    {
        if(m_iNum != rhs.m_iNum)
            return false;
        else
            return true;
    }

    bool operator<(const MyTest& rhs) const
    {
        if(m_iNum < rhs.m_iNum)
            return true;
        else
            return false;
    }

private:
    int m_iNum;
};

bool int_ptr_less1(int* a, int* b)   //辅助函数
{
    return *a < *b;
}

bool int_ptr_less2(int* a, int* b)
{
    return *a > *b;
}

void mySwap()
{
    int x = 17;
    int y = 42;

    int *px = &x;
    int *py = &y;
    int *pmax = nullptr;

    pmax = max(px, py, int_ptr_less1);    //返回较大值

    cout << *pmax << endl;

    int a = 10;
    int b = 11;

    swap(a, b);

    cout << a << " " << b << endl;
}

void myOperator()
{
    using namespace rel_ops;

    MyTest T1(11);
    MyTest T2(6);

    if(T1 == T2)
        cout << "T1 == T2" << endl;
    else if(T1 < T2)
        cout << "T1 < T2" << endl;
    else if(T1 != T2)
        cout << "T1 != T2" << endl;
    else if(T1 > T2)
        cout << "T1 > T2" << endl;
    else if(T1 >= T2)
        cout << "T1 >= T2" << endl;
    else if(T1 <= T2)
        cout << "T1 <= T2" << endl;
}

int main()
{
    //mySwap();

    myOperator();

    return 0;
}











