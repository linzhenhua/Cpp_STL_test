
#include <iostream>
#include <exception>
#include <cstdlib>

using namespace std;

int fun(const int x, const int y)
{
    if(y == 0)
        exit(-1);
        //throw y;
    return x/y;
}

int main()
{
    //try{
        cout << fun(10, 0) << endl;
    //}
    //catch(int ){
        //cout << "除数不能为0" << endl;
        //return -1;
    //}

    return 0;
}

/*
// exception example
#include <iostream>       // std::cerr
#include <typeinfo>       // operator typeid
#include <exception>      // std::exception

class Polymorphic
{
    virtual void member() {}
};

int main ()
{
    try
    {
        Polymorphic * pb = 0;
        typeid(*pb);  // throws a bad_typeid exception
    }
    catch (std::exception& e)
    {
        std::cerr << "exception caught: " << e.what() << '\n';
    }
    return 0;
}
*/
/*
#include <iostream>
#include <new>

using namespace std;

int main()
{
    try{
        int *p = new int[1000000000];

        delete []p;
    }
    catch(std::bad_alloc& e){
        cerr << e.what() << endl;
        return -1;
    }

    return 0;
}
*/
/*
// out_of_range example
#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector

int main (void)
{
    std::vector<int> myvector(10);

    try
    {
        myvector.at(20)=100;      // vector::at throws an out-of-range
    }
    catch (const std::out_of_range& oor)
    {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }

    return 0;
}
*/
/*
#include <iostream>

using namespace std;

class MyExecption{
public:
    MyExecption(int errorId, int errorLine, string errorInfo, string errorFile):
        m_errorId(errorId), m_errorLine(errorLine), m_errorInfo(errorInfo),
        m_errorFile(errorFile){}

    MyExecption(const MyExecption& rhs)
    {
        m_errorId = rhs.m_errorId;
        m_errorLine = rhs.m_errorLine;
        m_errorInfo = rhs.m_errorInfo;
        m_errorFile = rhs.m_errorFile;
    }

    ~MyExecption(){}

    void what() const
    {
        cout << m_errorId << '\n' << m_errorLine
        << '\n' << m_errorInfo << '\n' << m_errorFile << endl;
    }

private:
    int m_errorId;
    int m_errorLine;
    string m_errorInfo;
    string m_errorFile;
};

int main()
{
    int throwCode = 100;

    cin >> throwCode;

    try{
        if(throwCode == 100)
            throw MyExecption(throwCode, __LINE__, "error 100", __FILE__);
        else
            throw MyExecption(throwCode, __LINE__, "error 100", __FILE__);
    }
    catch(const MyExecption& e){
        e.what();
    }

    return 0;
}
*/
