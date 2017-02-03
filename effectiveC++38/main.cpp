//将list应用于set
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

template <class T>
class Myset{
public:
    bool member(const T& item) const;
    void insert(const T& item);
    void remove(const T& item);
    size_t size() const;

private:
    list<T> myList;
};

template<class T>
bool Myset<T>::member(const T& item) const
{
    return find(myList.begin(), myList.end(), item) != myList.end();
}

template <class T>
void Myset<T>::insert(const T& item)
{
    if(!member(item))
    {
        myList.push_back(item);
    }
}

template<class T>
void Myset<T>::remove(const T& item)
{
    //typename指出下面紧跟着的名称是一个类型,而不是一个成员变量
    typename list<T>::iterator iter = find(myList.begin(), myList.end(), item);
    if(iter != myList.end())
    {
        myList.erase(iter);
    }
}

template <class T>
size_t Myset<T>::size() const
{
    return myList.size();
}

class Empty{
};

int main()
{
    Myset<int> S;

    for(int i = 0; i < 10; ++i)
    {
        S.insert(i);
    }

    if(true == S.member(1))
    {
        cout << "S have 1" << endl;
    }

    cout << S.size() << endl;

    S.remove(9);

    cout << S.size() << endl;

    cout << sizeof(Empty) << endl;

    return 0;
}

/*
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
template <class T>
class MySet
{
private:
    list<T> MyList;

public:
    int Size() const
    {
        return MyList.size();
    }

    bool IsContained(T Element) const
    {
        return (find(MyList.begin(), MyList.end(), Element) != MyList.end());
    }

    bool Insert(T Element)
    {
        if (!IsContained(Element))
        {
            MyList.push_back(Element);
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Remove(T Element)
    {
        typename list<T>::iterator Iter =
        find(MyList.begin(), MyList.end(), Element);
        if (Iter != MyList.end())
        {
            MyList.erase(Iter);
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    return 0;
}
*/
/*
#include<iostream>
using namespace std;

class test {
private :

    char c;     //1byte
    int i;      //4byte
    short s;    //2byte
};

int main()
{
    cout << sizeof(test) << endl;

    return 0;
}
*/
