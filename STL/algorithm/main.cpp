#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void myRemove()
{
    vector<int> myVec;

    for(int i = 0; i != 10; ++i)
    {
        myVec.push_back(i);
    }

    for(vector<int>::const_iterator iter = myVec.begin(); iter != myVec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vector<int>::iterator removeIter;
    removeIter = remove(myVec.begin(), myVec.end(), 8);
    //remove(myVec.begin(), myVec.end(), 7);
    //remove(myVec.begin(), myVec.end(), 1);

    for(vector<int>::const_iterator iter = myVec.begin(); iter != myVec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vector<int>::iterator findIter;
    findIter = find(myVec.begin(), myVec.end(), 2);
    myVec.erase(findIter, myVec.end());
/*
    vector<int>::iterator tempIter = myVec.erase(findIter, findIter+2);

    cout << *tempIter << endl;
*/
    for(vector<int>::const_iterator iter = myVec.begin(); iter != myVec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

void myAlgorithm()
{
    vector<int> vec;

    //插入元素
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(9);
    vec.push_back(8);

    //遍历
    for(vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vector<int>::iterator pos;

    //最小值
    pos = min_element(vec.begin(), vec.end());
    cout << "min elem: " << *pos << endl;

    //最大值
    pos = max_element(vec.begin(), vec.end());
    cout << "max elem: " << *pos << endl;

    //排序
    sort(vec.begin(), vec.end());
    for(vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    //查找元素
    pos = find(vec.begin(), vec.end(), 4);
    if(pos != vec.end())
        cout << "find: " << *pos << endl;

    //反转
    reverse(pos, vec.end());
    for(vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    /*
    reverse(vec.begin(), vec.end());
    for(vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
    */
}

int Mul2(int &x)
{
    return x = x*2;
}

bool IsOdd(int x)
{
    return x%2 != 0;
}

void Print(int x)
{
    cout << x << " ";
}

void ForEach()
{
    vector<int> vec;

    for(int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
/*
    for_each(vec.begin(), vec.end(), Mul2);

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for_each( vec.begin(), vec.end(), not1( ptr_fun(IsOdd) ) );

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
*/

    for_each(vec.begin(), vec.end(), Print);
}

void Count()
{
    vector<int> vec;

    for(int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //int my_count = count(vec.begin(), vec.end(), 1);

    int my_count = count_if(vec.begin(), vec.end(), IsOdd);

    cout << my_count << endl;
}

void MinElement()
{
    vector<int> vec;

    for(int i = 1; i < 10; ++i)
    {
        vec.push_back(i);
    }
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int>::iterator my_min_element = min_element(vec.begin(), vec.end());

    cout << *my_min_element << endl;

    vector<int>::iterator my_max_element = max_element(vec.begin(), vec.end());

    cout << *my_max_element << endl;
}

void Find()
{
    vector<int> vec;

    for(int i = 2; i < 10; ++i)
    {
        vec.push_back(i);
    }
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
/*
    //find()函数记得判断返回值
    vector<int>::iterator iter = find(vec.begin(), vec.end(), 10);
    if(iter == vec.end())
        return ;
    cout << *iter << endl;
*/
    vector<int>::iterator iter1 = find_if(vec.begin(), vec.end(), IsOdd);
    if(iter1 == vec.end())
        return ;
    cout << *iter1 << endl;

}

void Search()
{
    vector<int> vec;

    for(int i = 2; i < 10; ++i)
    {
        vec.push_back(i);
    }
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    int arr[] = {5,6,7,8};

    vector<int>::iterator iter = search(vec.begin(), vec.end(), arr, arr+4);
    if(iter != vec.end())
    {
        cout << iter - vec.begin() << endl;
        cout << *iter << endl;
    }
}

int main()
{
    //myAlgorithm();

    //myRemove();

    //ForEach();

    //Count();

    //MinElement();

    //Find();

    Search();

    return 0;
}
