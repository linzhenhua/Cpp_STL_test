#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

bool compFun(const int &x, const int &y)
{
    return (x > y);
}

//仿函数
class compClass
{
public:
    bool operator() (const int &lhs, const int &rhs) const
    {
        return (lhs > rhs);
    }
};

void mySet()
{
    set<int> mySet1();
    //空的set不能打印输出
    //set<int>::iterator iter = mySet1.begin();
    //cout << *iter << endl;

    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    set<int> mySet2(arr, arr+sizeof(arr)/sizeof(int));
    copy(mySet2.begin(), mySet2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    set<int, compClass> mySet3(arr, arr+sizeof(arr)/sizeof(int));

    //swap(mySet3, mySet2);
    copy(mySet3.begin(), mySet3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    set<int, compClass> mySet4(mySet3);
    copy(mySet4.begin(), mySet4.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    bool (*ptrFun)(const int&, const int&) = compFun;

    set<int, bool(*)(const int&, const int&)> mySet5(arr, arr+sizeof(arr)/sizeof(int), ptrFun);
    copy(mySet5.begin(), mySet5.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

//模板类
template<class T>
class RuntimeCmp{
public:
    enum cmp_mode{_normal, _reverse};   //0, 1

private:
    cmp_mode mode;

public:
    RuntimeCmp(cmp_mode m = _normal):mode(m){}

    bool operator() (const T& t1, const T& t2) const
    {
        return mode == _normal ? t1 < t2 : t2 < t1;
    }

    bool operator== (const RuntimeCmp& rc)
    {
        return mode == rc.mode;
    }
};

typedef set<int, RuntimeCmp<int> > IntSet;

void fillElem(IntSet& _set)
{
    _set.insert(4);
    _set.insert(7);
    _set.insert(5);
    _set.insert(1);
    _set.insert(6);
    _set.insert(2);
    _set.insert(5);
}

void mySet1()
{
    IntSet coll1;
    fillElem(coll1);

    for(IntSet::iterator iter = coll1.begin(); iter != coll1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    RuntimeCmp<int> reverse_order(RuntimeCmp<int>::_reverse);

    IntSet coll2(reverse_order);
    fillElem(coll2);
    for(IntSet::iterator iter = coll2.begin(); iter != coll2.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    coll1 = coll2;
    coll1.insert(3);
    for(IntSet::iterator iter = coll1.begin(); iter != coll1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    if(coll1.value_comp() == coll2.value_comp())
    {
        cout << "coll1 and coll2 have same sorting criterion" << endl;
    }
    else
    {
        cout << "coll1 and coll2 have different sorting criterion" << endl;
    }
}

void mySet2()
{
    int arr[9] = {0,1,2,4,5,6,7,8,9};
    set<int> mySet1(arr, arr+sizeof(arr)/sizeof(int));
    copy(mySet1.begin(), mySet1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << mySet1.size() << endl;
    cout << mySet1.empty() << endl;
    cout << mySet1.max_size() << endl;
    cout << mySet1.count(3) << endl;     //可用于判断一个元素是否存在于set容器

    if(mySet1.find(9) != mySet1.end())
    {
        cout << "9 is an element of myset1." << endl;
    }
    else
    {
        cout << "9 is not an element of myset1." << endl;
    }

    cout << *mySet1.lower_bound(3) << endl;
    cout << *mySet1.upper_bound(3) << endl;
    cout << *mySet1.equal_range(3).first << " and " << *mySet1.equal_range(3).second << endl;
}

int main()
{
    //mySet();

    //mySet1();

    mySet2();

    return 0;
}
