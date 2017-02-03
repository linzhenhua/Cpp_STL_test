#include <iostream>

using namespace std;

class Test{
public:
    Test(const int &x, const int &y):m_iX(x), m_iY(y){}

    virtual ~Test(){}

    Test(const Test &rhs);

    Test& operator=(const Test &rhs);

    virtual void purPrint() = 0;

    inline void print() const;

    void print1() const
    {
        cout << "Test print1()" << endl;
    }

    void print1(int x) const
    {
        cout << "Test print1(int x)" << endl;
    }

    virtual void print2() const
    {
        cout << "Test print2()" << endl;
    }

private:
    int m_iX;
    int m_iY;
};

class Test1 : public Test{
public:
    Test1(const int x1, const int y1, const int x2, const int y2):
        Test(x1, y1), x(x2), y(y2){}

    ~Test1(){}

    Test1(const Test1 &rhs);

    Test1& operator=(const Test1 &rhs);

    virtual void purPrint();

    void print1() const
    {
        cout << "Test1 print1()" << endl;
    }

    virtual void print2() const
    {
        cout << "Test1 print2()" << endl;
    }

    void print1(int x) const
    {
        cout << "Test1 print1(int x)" << endl;
    }

//using Test::print1;

    void print3() const
    {
        Test::print1(1);
    }

private:
    int x;
    int y;

};

Test::Test(const Test &rhs)
{
    m_iX = rhs.m_iX;
    m_iY = rhs.m_iY;
}

Test& Test::operator=(const Test &rhs)
{
    m_iX = rhs.m_iX;
    m_iY = rhs.m_iY;

    return *this;
}

inline void Test::print() const
{
    cout << m_iX << " " << m_iY << endl;
}

void Test::purPrint()
{
    cout << "purPrint" << endl;
}

Test1::Test1(const Test1 &rhs):Test(rhs)
{
    x = rhs.x;
    y = rhs.y;
}

Test1& Test1::operator=(const Test1 &rhs)
{
    Test::operator=(rhs);
    x = rhs.x;
    y = rhs.y;

    return *this;
}

void Test1::purPrint()
{
    cout << "purPrint1" << endl;
}

int main()
{
    //Test T(1,2);

    Test1 T1(1,2,3,4);

    T1.print1();

    T1.print2();

    T1.print();

    T1.print1(1);

    T1.print3();

    T1.purPrint();

    T1.Test::purPrint();

    return 0;
}
