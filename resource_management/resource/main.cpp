#include <iostream>
#include <string>
#include <memory>

using namespace std;

#define Max(x,y) ((x) > (y) ? (x):(y))   //����ʹ����������

class Resou{
public:
    explicit Resou(const int x)
    {
        m_iNum = x;
        ptr = new char('a');
        cout << "���캯��" << endl;
    }
    ~Resou()
    {
        delete ptr;
        ptr = NULL;

        cout << "��������" << endl;
    }

    operator int()     //��ʽת����ʹ�����ת��Ϊint��
    {
        return m_iNum;
    }

    void print()
    {
        string str("abcdefg");
        ptr = const_cast<char*>(str.c_str());   //ȥ��const����

        cout << ptr << endl;
    }

private:
    Resou(const Resou&){}
    Resou& operator=(const Resou&){}

private:
    char *ptr;
    int m_iNum;
};

int main()
{
    int num = 1;
    int x = Max(6,10);
    Resou X (x);

    cout << num + X << endl;

    X.print();

    return 0;
}
