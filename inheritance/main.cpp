#include <iostream>

using namespace std;

class Test1
{
public:
    Test1()
    {
        a = 1;
        b = 2;
        c = 3;
    }

    void print()
    {
        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
    }
public:
    int a;
protected:
    int b;
private:
    int c;
};

class Test2 : private Test1
{
public:
    Test2(){}
};


int main()
{
    Test1 A;
    Test2 B;
    char arr[10]; //char *const pointer;

    //cout << A.a << endl;
    //cout << A.b << endl;
    //cout << A.c << endl;
    //cout << B.a << endl;
    //cout << B.b << endl;
    //cout << B.c << endl;
    cout << sizeof(arr) << endl;

    return 0;
}
