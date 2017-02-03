#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Clock{
public:
    Clock(const int x):m_iNum(x)   //构造函数
    {
        cout << "父类默认构造函数" << endl;
    }

    Clock(const Clock &rhs):m_iNum(rhs.m_iNum)         //复制构造函数
    {
        //m_iNum = rhs.m_iNum;
        cout << "父类复制构造函数" << endl;
    }

    Clock& operator=(const Clock &rhs)   //重载=号操作符
    {
        m_iNum = rhs.m_iNum;

        cout << "父类重载=号操作符" << endl;

        return *this;
    }

    virtual ~Clock()
    {
        cout << "父类析构函数" << endl;
    }

private:
    int m_iNum;
};

class Clock1 : public Clock{
public:
    Clock1(const int x, const int y):m_iNum1(x),Clock(y)
    {
        cout << "子类构造函数" << endl;
    }

    Clock1(const Clock1 &rhs):m_iNum1(rhs.m_iNum1),Clock(rhs)
    {
        //m_iNum1 = rhs.m_iNum1;

        cout << "子类复制构造函数" << endl;
    }

    Clock1& operator=(const Clock1 &rhs)
    {
        Clock::operator=(rhs);

        m_iNum1 = rhs.m_iNum1;

        cout << "子类重载=操作符" << endl;

        return *this;
    }

    ~Clock1()
    {
        cout << "子类析构函数" << endl;
    }

private:
    int m_iNum1;
};

int main(void)
{
    Clock C1(1);   //调用构造函数
    Clock C2(C1);  //调用复制构造函数
    C2 = C1;       //重载=号操作符

    Clock1 C3(1,2);
    Clock1 C4(C3);
    C4 = C3;

    return 0;
}
