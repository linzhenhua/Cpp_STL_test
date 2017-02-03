#include <iostream>

using namespace std;

template<typename T>
class Test{
public:
    void print1()
    {
        cout << "Test print1" << endl;
    }

    void print2()
    {
        cout << "Test print2" << endl;
    }
};

template<typename T>
class Test1 : public Test<T>
{
public:
    using Test<T>::print1;
    void print3()
    {
        cout << "Test1 start" << endl;
        //this->print1();
        //Test<T>::print1();
        print1();
        cout << "Test1 end" << endl;
    }
};

int main()
{
    Test1<int> T;

    T.print1();
    T.print2();
    T.print3();

    return 0;
}
