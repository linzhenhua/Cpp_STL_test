//NVI non-virtual interface

#include <iostream>

using namespace std;

class Test{
public:
    Test(const int x, const int y):m_iX(x), m_iY(y){}

    virtual ~Test(){}

    Test(const Test& rhs)
    {
        m_iX = rhs.m_iX;
        m_iY = rhs.m_iY;
    }

    Test& operator=(const Test& rhs)
    {
        m_iX = rhs.m_iX;
        m_iY = rhs.m_iY;

        return *this;
    }

    void print1() const
    {
        //事前工作
        print();
        //事后工作
    }

    void print2() const
    {
        cout << "Test print2" << endl;
    }

    virtual void print3(int x = 1) const
    {
        cout << "Test print3() " << x << endl;
    }

private:
    virtual void print() const
    {
        cout << "Test print" << endl;
    }

private:
    int m_iX;
    int m_iY;
};

class Test1 : public Test{
public:
    Test1(const int x, const int y, const int a, const int b):
        Test(x, y), x(a), y(b){}

    ~Test1(){}

    Test1(const Test1& rhs):Test(rhs)
    {
        x = rhs.x;
        y = rhs.y;
    }

    Test1& operator=(const Test1& rhs)
    {
        Test::operator=(rhs);
        x = rhs.x;
        y = rhs.y;

        return * this;
    }
/*
    void print2() const
    {
        cout << "Test print2" << endl;
    }
*/
    virtual void print3(int x = 2) const
    {
        cout << "Test1 print3() " << x << endl;
    }

private:
    virtual void print() const
    {
        cout << "Test1 print" << endl;
    }

private:
    int x;
    int y;

};

int main()
{
    Test T1(1,2);
    T1.print1();

    Test1 T2(1,2,3,4);
    T2.print1();

    T2.print2();

    T1.print3();
    T2.print3();

    Test *T3 = &T2;

    T3->print3();

    return 0;
}
