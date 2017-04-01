#include <stdlib.h>
#include <math.h>

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

void Mem_fun()
{
    //字符串常量
    const char* arr[] = {"one", "two", "three", "four", "five", "six"};

    vector<string> vec( arr, arr + sizeof(arr) / sizeof(char*) );

    for(vector<string>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vector<int> number( vec.size() );
    transform( vec.begin(), vec.end(), number.begin(), mem_fun_ref(&string::length) );

    copy(number.begin(), number.end(), ostream_iterator<int>(cout, " "));
}

void Ptr_fun()
{
    //字符串常量
    const char* arr[] = {"1", "2", "3", "4"};

    int arr1[4];

    transform(arr, arr+4, arr1, ptr_fun( atoi ) );

    for(int i = 0; i <= 3; ++i)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
}

template<class T1, class T2>
class Fopow : public binary_function<T1, T2, T1>
{
public:
    T1 operator() (T1 base, T2 exp) const
    {
        return pow(base, exp);
    }
};

void Custom()
{
    vector<int> vec;
    for(int i = 1; i <= 9; ++i)
    {
        vec.push_back(i);
    }
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " ") );
    cout << endl;

    transform(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "), bind2nd(Fopow<float, int>(), 3));
}

int main()
{
    //Mem_fun();

    //Ptr_fun();

    Custom();

    return 0;
}
