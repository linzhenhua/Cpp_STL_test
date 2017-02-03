#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Clock{
public:
    Clock(const int x):m_iNum(x)   //���캯��
    {
        cout << "����Ĭ�Ϲ��캯��" << endl;
    }

    Clock(const Clock &rhs):m_iNum(rhs.m_iNum)         //���ƹ��캯��
    {
        //m_iNum = rhs.m_iNum;
        cout << "���ิ�ƹ��캯��" << endl;
    }

    Clock& operator=(const Clock &rhs)   //����=�Ų�����
    {
        m_iNum = rhs.m_iNum;

        cout << "��������=�Ų�����" << endl;

        return *this;
    }

    virtual ~Clock()
    {
        cout << "������������" << endl;
    }

private:
    int m_iNum;
};

class Clock1 : public Clock{
public:
    Clock1(const int x, const int y):m_iNum1(x),Clock(y)
    {
        cout << "���๹�캯��" << endl;
    }

    Clock1(const Clock1 &rhs):m_iNum1(rhs.m_iNum1),Clock(rhs)
    {
        //m_iNum1 = rhs.m_iNum1;

        cout << "���ิ�ƹ��캯��" << endl;
    }

    Clock1& operator=(const Clock1 &rhs)
    {
        Clock::operator=(rhs);

        m_iNum1 = rhs.m_iNum1;

        cout << "��������=������" << endl;

        return *this;
    }

    ~Clock1()
    {
        cout << "������������" << endl;
    }

private:
    int m_iNum1;
};

int main(void)
{
    Clock C1(1);   //���ù��캯��
    Clock C2(C1);  //���ø��ƹ��캯��
    C2 = C1;       //����=�Ų�����

    Clock1 C3(1,2);
    Clock1 C4(C3);
    C4 = C3;

    return 0;
}
