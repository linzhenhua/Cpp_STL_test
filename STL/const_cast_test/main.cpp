#include <iostream>
#include <string>

using namespace std;

void test()
{
    const int a = 100;

    int *p = const_cast<int *>(&a);

    *p = 10;       //��ͼ�޸�a��ֵ �ᵼ��δ������Ϊ

    cout << "*p = " << *p << "\na = " << a << endl;
    //�����
    //*p = 10
    //a = 100            a��ֵ���ɲ��ܸı�

    cout << "&a = " << &a << "\np = " << p << endl;
     //�����
     //&a = 0x28ff08
     //p = 0x28ff08
}

int main()
{
    test();

    return 0;
}
