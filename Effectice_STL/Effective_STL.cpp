#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <memory>
#include <set>
#include <map>
#include <string>
#include <cctype>

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
    delete []p;
}

void effective_7()
{
    vector<int *> vecptr;

    //分配内存
    for(int i = 0; i < 10; ++i)
    {
        int *p = new int[10];

        vecptr.push_back(p);
    }

    //释放内存1
    //for(vector<int *>::iterator i = vecptr.begin(); i != vecptr.end(); ++i)
    //{
    //    delete *i;
    //}

    //释放内存2
    for_each(vecptr.begin(), vecptr.end(), fun);

    {
        //释放内存3：使用智能指针自动管理
        //test begin
        shared_ptr<int> sp(new int);

        *sp = 10;

        cout << *sp << endl;
        //test end
    }

    vector< shared_ptr<int> > vec;

    for(int i = 0; i < 5; ++i)
    {
        shared_ptr<int> p(new int(i) );

        vec.push_back(p);
    }

}

void effective_17()
{
    vector<int> vec;

    vec.reserve(100);

    for(int i = 0; i < 100; ++i)
    {
        vec.push_back(i);
    }

    cout << vec.size() << endl;

    vector<int>().swap(vec);

    cout << vec.size() << endl;
}

void effective_16()
{
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> vec;

    vec.reserve(10);

    vec.insert(vec.begin(), arr, arr+sizeof(arr)/sizeof(int));

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    int *p = nullptr;

    p = &vec[0];

    vector<int>::iterator iter = vec.begin()+2;

    p = &*iter;

    cout << *p << endl;

}

//一个不考虑大小写的比较仿函数
class FunComp
{
public:
    bool operator()(const string &lhs, const string &rhs) const
    {
        string temp1;
        temp1.reserve(lhs.size());

        char arr;

        for(int i = 0; i < lhs.size(); ++i)
        {
            if( 'a' <= lhs[i] && lhs[i] <= 'z' )
            {
                temp1.push_back(lhs[i]);
            }
            else
            {
                arr = lhs[i] + 32;
                temp1.push_back(arr);
            }
        }

        //string().swap(temp1);       //清空temp1
        //temp1.reserve(rhs.size());

        string temp2;
        temp2.reserve(rhs.size());

        for(int i = 0; i < rhs.size(); ++i)
        {
            if( 'a' <= rhs[i] && rhs[i] <= 'z' )
            {
                temp2.push_back(rhs[i]);
            }
            else
            {
                arr = rhs[i] + 32;        //如果是大写字母，则变成小写
                temp2.push_back(arr);
            }
        }

        //cout << temp1 << " ";
        //cout << endl;

        return temp1 < temp2;
    }
};

/*
bool test(const string &lhs, const string &rhs)
{
    string temp1;
    temp1.reserve(lhs.size());

    char arr;

    for(int i = 0; i < lhs.size(); ++i)
    {
        if( 'a' <= lhs[i] && lhs[i] <= 'z' )
        {
            temp1.push_back(lhs[i]);
        }
        else
        {
            arr = lhs[i] + 32;
            temp1.push_back(arr);
        }
    }

    //string().swap(temp1);       //清空temp1
    //temp1.reserve(rhs.size());

    string temp2;
    temp2.reserve(rhs.size());

    for(int i = 0; i < rhs.size(); ++i)
    {
        if( 'a' <= rhs[i] && rhs[i] <= 'z' )
        {
            temp2.push_back(rhs[i]);
        }
        else
        {
            arr = rhs[i] + 32;        //如果是大写字母，则变成小写
            temp2.push_back(arr);
        }
    }

    //cout << temp1 << endl;

    cout << temp2 << endl;

    return temp1 < temp2;
}
*/

void effective_19()
{
    //set<string, FunComp> Set;

    string arr[10] = {"A", "b", "C", "d", "E", "F", "g", "h", "I", "J"};

    //cout << "sizeof(arr):" << sizeof(arr) << "  " << sizeof(string) << endl;

    //vector<string> vec(arr, arr+sizeof(arr)/sizeof(char));

    set<string, FunComp> Set;
    Set.insert(arr, arr+sizeof(arr)/sizeof(string));

    //copy(Set.begin(), Set.end(), ostream_iterator<string>(cout, " ") );
    //cout << endl;

    for(set<string, FunComp>::const_iterator iter = Set.begin(); iter != Set.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

//如果两个数相同，返回false
class Fun1
{
public:
    bool operator()(const int& lhs, const int& rhs) const
    {
        if(lhs > rhs)
        {
            return true;
        }
        else if(lhs < rhs)
        {
            return false;
        }
        else if(lhs == rhs)
        {
            return false;
        }
    }
};

void effective_21()
{
    set<int, less_equal<int> > Set;

    Set.insert(10);

    Set.insert(10);

    for(set<int, less_equal<int> >::iterator iter = Set.begin(); iter != Set.end(); ++iter )
    {
        cout << *iter << endl;
    }
    cout << endl;

    set<int, Fun1> Set1;

    Set1.insert(10);

    Set1.insert(10);

    for(set<int, Fun1>::iterator iter = Set1.begin(); iter != Set1.end(); ++iter)
    {
        cout << *iter << endl;
    }
    cout << endl;

    multiset<int> Mset;

    Mset.insert(10);

    Mset.insert(10);

    for(multiset<int>::iterator iter = Mset.begin(); iter != Mset.end(); ++iter)
    {
        cout << *iter << endl;
    }
}

void effective_28()
{
    vector<int> vec;
    vec.reserve(5);

    for(int i = 0; i <= 5; ++i)
    {
        vec.push_back(i);
    }
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int>::reverse_iterator ri = find(vec.rbegin(), vec.rend(), 3);

    //插入操作
    vec.insert(ri.base(), 99);

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    ri = find(vec.rbegin(), vec.rend(), 99);
    vec.erase((++ri).base());

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void effective_31()
{
    cout << "test nth_element: " << endl;

    vector<int> vec;

    vec.reserve(10);

    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(9);
    vec.push_back(4);
    vec.push_back(8);
    vec.push_back(3);
    vec.push_back(7);
    vec.push_back(0);

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //random_shuffle(vec.begin(), vec.end());

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    nth_element(vec.begin(), vec.begin()+5, vec.end());

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "test partial_sort: " << endl;
    //partial_sort
    vector<int> vec1;

    vec1.reserve(10);

    vec1.push_back(2);
    vec1.push_back(1);
    vec1.push_back(5);
    vec1.push_back(6);
    vec1.push_back(9);
    vec1.push_back(4);
    vec1.push_back(8);
    vec1.push_back(3);
    vec1.push_back(7);
    vec1.push_back(0);

    copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //random_shuffle(vec1.begin(), vec1.end());

    copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    partial_sort(vec1.begin(), vec1.begin()+5, vec1.end());

    copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void effective_32()
{
    vector<int> vec;

    vec.reserve(10);

    for(int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }

    vec[1] = vec[3] = vec[5] = 99;

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << vec.size() << endl;

    vector<int>::iterator iter = remove(vec.begin(), vec.end(), 99);

    //copy(vec.begin(), iter, ostream_iterator<int>(cout, " "));
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vec.erase(iter, vec.end());

    cout << vec.size() << endl;
}

bool fun33(const shared_ptr<int> &x)
{
    return 99 == *x;
}

void effective_33()
{
    vector<int*> vec;

    vec.reserve(10);

    for(int i = 0; i < 10; ++i)
    {
        vec.push_back( new int(i) );
    }

    for(vector<int*>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << **iter << " ";
    }
    //copy(vec.begin(), vec.end(), ostream_iterator<int*>(cout, " "));
    cout << endl;

    for(vector<int*>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        delete *iter;
        *iter = nullptr;
    }

    //使用智能指针
    vector<shared_ptr<int> > vec1;

    vec1.reserve(10);

    for(int i = 0; i < 10; ++i)
    {
        vec1.push_back( shared_ptr<int>(new int(i)) );
    }

    for(vector<shared_ptr<int> >::iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
    {
        cout << **iter << " ";
    }
    cout << endl;

    *vec1[1] = *vec1[3] = *vec1[5] = 99;

    for(vector<shared_ptr<int> >::iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
    {
        cout << **iter << " ";
    }
    cout << endl;

    vec1.erase( remove_if(vec1.begin(), vec1.end(), fun33), vec1.end() );

    for(vector<shared_ptr<int> >::iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
    {
        cout << **iter << " ";
    }
    cout << endl;
}

bool fun35(char c1, char c2)
{
    return tolower(c1) > tolower(c2);
}

void effective_35()
{
    string str1("linzhenhub");
    string str2("LINZHENHUA");

    bool flag;
    flag = lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end(), fun35);

    cout << std::boolalpha;
    cout << flag << endl;
}
























