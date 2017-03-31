#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

class Functor{
public:
    Functor(const int &x):value_(x){};

    Functor(const Functor& rhs)
    {
        value_ = rhs.value_;
    }

    Functor operator=(const Functor &rhs)
    {
        if(this == &rhs)
        {
            return *this;
        }

        value_ = rhs.value_;

        return *this;
    }

    bool operator() (const int x) const
    {
        return (x % 2 == 0);
    }

    operator int()
    {
        return value_;
    }

private:
    int value_;
};

class Myclass {
public:
    Myclass(const int x):value_(x){}

    void operator() (int i) const
    {
        cout << ' ' << i;
    }

private:
    int value_;
};

void fun1()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vec(arr, arr+10);

    //Myclass myclass;

    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vector<int>::iterator itera;
    itera = find_if(vec.begin(), vec.end(), Functor(5));  //find_if要求Functor返回bool值

    if(itera != vec.end())
    {
        cout << *itera << endl;
    }

    //for_each(vec.begin(), vec.end(), Myclass(1));

    //for_each(vec.begin(), vec.end(), Functor(2));

    //Functor myFun(10);

    //cout << endl;
    //cout << myFun + 10 << endl;

    vector<int>::iterator i = remove_if(vec.begin(), vec.end(), Functor(2));
    copy(vec.begin(), i, ostream_iterator<int>(cout, " "));
}

int main()
{
    fun1();

    return 0;
}
