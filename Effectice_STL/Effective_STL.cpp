#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

void effective_5()
{
    vector<int> v1;
    vector<int> v2;

    v1.reserve(5);

    for(int i = 0; i < 5; ++i)
    {
        v1.push_back(i);
    }

    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //方式1
    //v2.assign(v1.begin(), v1.end());

    //方式2
    //copy(v1.begin(), v1.end(), back_inserter(v2));

    //方式3
    //for(vector<int>::const_iterator i = v1.begin(); i < v1.end(); ++i)
    //{
    //    v2.push_back(*i);
    //}

    //方式4
    v2.insert(v2.begin(), v1.begin(), v1.end());

    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void fun(int *p)
{
    delete p;
}

void effective_7()
{
    vector<int *> vecptr;

    //分配内存
    for(int i = 0; i < 10; ++i)
    {
        int *p = new int;

        vecptr.push_back(p);
    }

    //释放内存1
    //for(vector<int *>::iterator i = vecptr.begin(); i != vecptr.end(); ++i)
    //{
    //    delete *i;
    //}

    //释放内存2
    for_each(vecptr.begin(), vecptr.end(), fun);

    //释放内存3：使用智能指针自动管理
    //test begin
    shared_ptr<int> sp(new int);

    *sp = 10;

    cout << *sp << endl;
    //test end

    vector< shared_ptr<int> > vec;

    for(int i = 0; i < 5; ++i)
    {
        shared_ptr<int> p(new int(i) );

        vec.push_back(p);
    }

}










































