#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>
#include <cctype>

using namespace std;

/*
void myListInit()
{
    list<int> myList1;
    copy(myList1.begin(), myList1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    list<int> myList2(arr, arr+sizeof(arr)/sizeof(int));
    copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    list<int> myList3(myList2);
    copy(myList3.begin(), myList3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    list<int> myList4(10, 1);
    copy(myList4.begin(), myList4.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << myList4.size() << endl;
    cout << myList4.empty() << endl;
    cout << myList4.max_size() << endl;

    int arr1[] = {11,0,2,4,5,7,1,3,6,10,9};
    list<int> myList5(arr1, arr1+sizeof(arr1)/sizeof(int));
    myList5.sort();
    copy(myList5.begin(), myList5.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

//排序规则：
//按照a,b,c,d,e的英文字母顺序排序
//思路：one,two,Three,three
//用string存放每个单词，然后再用下标标识法把单词拆分成每个字母比较
bool comp(const string &first, const string &second)
{
    unsigned int i = 0;

    while( (i < first.length()) && (i < second.length()) )
    {
        if(tolower(first[i]) < tolower(second[i]))
            return true;
        else if(tolower(first[i]) > tolower(second[i]))
            return false;
        ++i;
    }

    //cout << "first.length()" << first.length() << endl;
    //cout << "second.length()" << second.length() << endl;
    //bool tmp = first.length() < second.length();
    //cout << "first.length() < second.length()" << tmp << endl;

    //单词相同时就有用了，顺序不变，因为两个相等的单词<的话return false
    return ( first.length() < second.length() );
}

void myListSort()
{
    list<string> myList;

    myList.push_back("one");
    myList.push_back("two");
    myList.push_back("three");
    myList.push_back("Three");

    cout << "排序前：" << endl;
    copy(myList.begin(), myList.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    myList.sort();    //默认排序方法

    cout << "默认排序：" << endl;
    copy(myList.begin(), myList.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    myList.sort(comp);

    cout << "使用外部函数排序：" << endl;
    copy(myList.begin(), myList.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
}

void myListDel()
{
    int arr[] = {0,1,2,3,2,4,5,6,7,3,8,9};
    list<int> myList(arr, arr+sizeof(arr)/sizeof(int));

    copy(myList.begin(), myList.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //只能删除第一个发现的元素
    myList.erase(find(myList.begin(), myList.end(), 3));
    copy(myList.begin(), myList.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //如果要删除一个容器里所有相同的元素
    myList.remove(2);
    copy(myList.begin(), myList.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void myListSplice()
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    list<int> myList1(arr, arr+5);
    list<int> myList2(arr+5, arr+10);

    copy(myList1.begin(), myList1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //myList1.splice(myList1.end(), myList2);

    //切记：find函数一定要判断查找到的元素的位置是否到了容器的末尾
    //myList1.splice(myList1.end(), myList2, find(myList2.begin(), myList2.end(), 7));

    myList1.splice(myList1.end(), myList2, find(myList2.begin(), myList2.end(), 7), myList2.end());
    copy(myList1.begin(), myList1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
*/
void myListMerge1()
{
    int arr[] = {0,1,3,2,4,5,6,8,7,9};
    list<int> myList1(arr, arr+5);
    list<int> myList2(arr+5, arr+10);

    copy(myList1.begin(), myList1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    myList1.merge(myList2);

    copy(myList1.begin(), myList1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

bool fun(int x, int y)
{
    return (x < y);
}

void myListMerge2()
{
    int arr[] = {3,1,5,7,9,0,2,4,6,8};
    list<int> myList1(arr, arr+5);
    list<int> myList2(arr+5, arr+10);

    copy(myList1.begin(), myList1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
/*
    myList2.reverse();
    cout << "myList2.reverse():" << endl;
    copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
*/

    myList1.merge(myList2, fun);

    copy(myList1.begin(), myList1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void myListUnique()
{
    int arr[] = {1,1,2,2,3,3,4,4};
    list<int> myList1(arr, arr+sizeof(arr)/sizeof(int));

    copy(myList1.begin(), myList1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    myList1.unique();

    copy(myList1.begin(), myList1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    int arr1[] = {1,2,2,3,1,3,4,4};
    list<int> myList2(arr1, arr1+sizeof(arr1)/sizeof(int));

    copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    myList2.unique();

    copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    //myListInit();

    //myListSort();

    //myListDel();

    //myListSplice();

    //myListMerge1();

    //myListMerge2();

    myListUnique();

    return 0;
}
