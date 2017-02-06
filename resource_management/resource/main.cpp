#include <iostream>
#include <string>
#include <memory>

using namespace std;

#define Max(x,y) ((x) > (y) ? (x):(y))   //尽量使用内联函数

class Resou{
public:
    explicit Resou(const int x)
    {
        m_iNum = x;
        ptr = new char('a');
        cout << "构造函数" << endl;
    }
    ~Resou()
    {
        delete ptr;
        ptr = NULL;

        cout << "析构函数" << endl;
    }

    operator int()     //隐式转换，使类对象转换为int型
    {
        return m_iNum;
    }

    void print()
    {
        string str("abcdefg");
        ptr = const_cast<char*>(str.c_str());   //去掉const限制

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
