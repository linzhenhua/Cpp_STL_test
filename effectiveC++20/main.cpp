#include <iostream>

using namespace std;

class Parent{
public:
    Parent(const int x)
    {
        m_iNum = x;
        cout << "父类构造函数" << endl;
    }
    virtual ~Parent()
    {
        cout << "父类析构函数" << endl;
    }

    void pirnt1() const
    {
        cout << "111" << endl;
    }

    virtual void print() const
    {
        cout << "parent" << endl;
    }

    friend void print3(const Parent &P);

private:
    int m_iNum;
};

class Children : public Parent{
public:
    Children(const int x): Parent(x)
    {
        cout << "子类构造函数" << endl;
    }
    ~Children()
    {
        cout << "子类析构函数" << endl;
    }

    void pirnt1() const
    {
        cout << "222" << endl;
    }

    virtual void print() const
    {
        cout << "Children" << endl;
    }
};

void print2(const Parent &x)
{
    x.print();
    x.pirnt1();
}

void print3(const Parent &P)    //友元函数
{
    cout << P.m_iNum << endl;
}

int main()
{
    Parent P(1000);
    Children C(100);

    //print2(P);
    print2(C);

    print3(P);

    return 0;
}
