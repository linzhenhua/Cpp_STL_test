#include <iostream>
#include <cstdio>

using namespace std;

class Test{
public:
    Test(int n1, int n2):m_iNum1(n1),m_iNum2(n2){}

    virtual ~Test(){}

    Test(const Test& rhs);

    Test& operator=(const Test& rhs);

    operator int() const;

    void printNum() const;

private:
    int m_iNum1;
    int m_iNum2;
};

class Test1 : public Test{
public:
    Test1(int x, int y, int z):Test(x, y), m_iNum(z){}

    ~Test1(){}

    Test1(const Test1 &rhs);

    Test1& operator=(const Test1 &rhs);

    void print() const;

private:
    int m_iNum;
};

Test::Test(const Test& rhs)
{
    m_iNum1 = rhs.m_iNum1;
    m_iNum2 = rhs.m_iNum2;
}

Test& Test::operator=(const Test& rhs)
{
    m_iNum1 = rhs.m_iNum1;
    m_iNum2 = rhs.m_iNum2;

    return *this;
}

Test::operator int() const
{
    return m_iNum1 + m_iNum2;
}

void Test::printNum() const
{
     cout << "m_iNum1: " << m_iNum1 << "\n"
     << "m_iNum2: " << m_iNum2 << endl;
}

Test1::Test1(const Test1 &rhs):Test(rhs)
{
    m_iNum = rhs.m_iNum;
}

Test1& Test1::operator=(const Test1 &rhs)
{
    m_iNum = rhs.m_iNum;
    Test::operator=(rhs);

    return *this;
}

void Test1::print() const
{
    cout << "m_iNum: " << m_iNum << "\n";
    printNum();
}

int main()
{
/*
    int x = 4;
    cout << x << endl;

    Test t(8, 2);
    x = t;

    cout << x << endl;

    int y = 4;
    float z = (float)y;

    cout << fixed << z << endl;
    printf("%f\n", z);

    float u = z;
    cout << u << endl;
*/

    int x = 1;
    int *ptr2 = NULL;

    const int *ptr1 = &x;
    //*const int ptr2 = &y;

    ptr2 = const_cast<int*>(ptr1);

    //ptr2 = ptr1;
    //cout << *ptr2 << endl;

    *ptr2 = 3;
    //cout << *ptr2 << endl;

    float y = 4.000000;
    int z = static_cast<int>(y);

    //printf("%f\n", z);
    //cout << fixed << z << endl;

    Test1 t1(1,2,3);

    Test1 t2(t1);

    //t2.print();

    //Test1 t3(4,5,6);
    //t3.print();

    //t3 = t2;

    //t3.print();

    return 0;
}
