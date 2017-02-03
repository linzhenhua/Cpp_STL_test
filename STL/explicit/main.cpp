#include <iostream>

using namespace std;

class Test{
public:
     explicit Test(const int i):m_iNum(i){}

    ~Test(){}

    Test(const Test& rhs):m_iNum(rhs.m_iNum){}

    Test& operator=(const Test& rhs)
    {
        m_iNum = rhs.m_iNum;

        return *this;
    }

    void print()
    {
        cout << m_iNum << endl;
    }

private:
    int m_iNum;
};

int main()
{
    Test T(1);
    T.print();

    Test T1('1');
    T1.print();

    //Test T2 = '2';  //error
    //T2.print();

    return 0;
}
