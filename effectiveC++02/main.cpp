#include <iostream>
#include <string>

using namespace std;

class Text{
public:
    Text(const int x = 10)//:z(x)
    {
        m_iNum = x;

        //z = x;

        cout << "OK" << endl;
    }

    ~Text(){}

    void print()
    {
        cout << m_iNum << endl;
    }

/*
    Text(const Text& rhs)
    {
        m_iNum = rhs.m_iNum;
    }

    Text& operator=(const Text& rhs)
    {
        m_iNum = rhs.m_iNum;

        return *this;
    }
*/
private:
    int m_iNum;

    //const static double x;

    //enum{y = 10};

    //const int z;

    //int arr[y];
};

//double const Text::x = 10.0;

namespace test{
    int x = 10;
}

void pri(int x = 1)
{
    cout << x << endl;
}

int main()
{

    Text T;
    T.print();

    Text T1(11);
    T1.print();

    pri();

    //int x = 1;

    //cout << test::x << endl;

    return 0;
}
