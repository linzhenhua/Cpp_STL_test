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

    //��ʽ1
    //v2.assign(v1.begin(), v1.end());

    //��ʽ2
    //copy(v1.begin(), v1.end(), back_inserter(v2));

    //��ʽ3
    //for(vector<int>::const_iterator i = v1.begin(); i < v1.end(); ++i)
    //{
    //    v2.push_back(*i);
    //}

    //��ʽ4
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

    //�����ڴ�
    for(int i = 0; i < 10; ++i)
    {
        int *p = new int;

        vecptr.push_back(p);
    }

    //�ͷ��ڴ�1
    //for(vector<int *>::iterator i = vecptr.begin(); i != vecptr.end(); ++i)
    //{
    //    delete *i;
    //}

    //�ͷ��ڴ�2
    for_each(vecptr.begin(), vecptr.end(), fun);

    //�ͷ��ڴ�3��ʹ������ָ���Զ�����
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










































