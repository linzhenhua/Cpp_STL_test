#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;

void fun(int x)
{
    cout << x << " ";
}

void myFor_each()
{
    vector<int> myVec;

    for(int i = 0; i != 10; ++i)
    {
        myVec.push_back(i);
    }

    for_each(myVec.begin(), myVec.end(), fun);

    cout << endl;
}

int square(int x)
{
    return x*x;
}

void myTransform()
{
    vector<int> myVec1;
    vector<int> myVec2;

    for(int i = 0; i != 10; ++i)
    {
        myVec1.push_back(i);
    }

    //打印输出myVec1
    copy(myVec1.begin(), myVec1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    transform(myVec1.begin(), myVec1.end(), back_inserter(myVec2), square);

    copy(myVec2.begin(), myVec2.end(), ostream_iterator<int>(cout, " "));
}

//一元判断式
/*
写函数三步走：
1、判断形参的条件（是否合理）
2、写业务逻辑
3、返回
*/
//判断是否为素数
//质数又称素数。指在一个大于1的自然数中，除了1和此整数自身外，不能被其他自然数整除的数
bool isPrime(int num)
{
    if(num <= 1)
        return false;

    //2,3,5,7,11,13,17,19
    for(int i = 2; i <= (int)sqrt((double)num); ++i) //test: 2,3,4,5,6,7,8
    {
        if(num % i == 0)
            return false;
    }
    //cout << num << " ";
    return true;
}

void myFind_if()
{
    vector<int> myVec;

    for(int i = 0; i <= 20; ++i)
    {
        myVec.push_back(i);
    }

    copy(myVec.begin(), myVec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> myVec1;
    vector<int>::iterator iter1 = myVec.begin();
    vector<int>::iterator iter2 = myVec.end();
    while(true)
    {
        //cout << *iter1 << endl;
        //iter1:0,1,2,3,4,5,6,7,8,9,10,iter2
              //-,-,
        vector<int>::iterator primeIter = find_if(iter1, iter2, isPrime);

        if(primeIter == iter2)
        {
            break;
        }
        else
        {
            myVec1.push_back(*primeIter);
        }
        iter1 = ++primeIter;
    }

    copy(myVec1.begin(), myVec1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

//二元判断式
bool comp(int x, int y)
{
    if(x < y)           //降序排序
        return false;
    else
        return true;
}

//仿函数
class comp1{
public:
    bool operator() (int x, int y) const  //重载函数调用操作符
    {
        if(x < y)           //降序排序
            return false;
        else
            return true;
    }
};

void mySort()
{
    vector<int> myVec;

    for(int i = 0; i < 10; ++i)
    {
        myVec.push_back(i);
    }

    copy(myVec.begin(), myVec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //sort(myVec.begin(), myVec.end(), comp);
    sort(myVec.begin(), myVec.end(), comp1());   //利用仿函数

    copy(myVec.begin(), myVec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

template<int theValue>   //以一个int常量值作为模板参数.
void add(int& elem)
{
    elem += theValue;
}

class AddValue{
public:
    AddValue(int x):theValue(x){}

    void operator() (int& x) const
    {
        x += theValue;
    }
private:
    int theValue;
};

//for_each(myVec.begin(), myVec.end(), AddValue(2));

void myTemplate()
{
    vector<int> myVec;

    for(int i = 0; i <= 10; ++i)
    {
        myVec.push_back(i);
    }

    copy(myVec.begin(), myVec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for_each(myVec.begin(), myVec.end(), add<10>);

    copy(myVec.begin(), myVec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for_each(myVec.begin(), myVec.end(), AddValue(2));

    copy(myVec.begin(), myVec.end(), ostream_iterator<int>(cout, " "));
}

int main()
{
    //myFor_each();

    //myTransform();

    myFind_if();

    //for(int x = 0; x <= 20; ++x)
    //    isPrime(x);

    //mySort();

    //myTemplate();

    return 0;
}
