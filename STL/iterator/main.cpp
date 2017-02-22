#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <deque>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

void myIterator()
{
    list<int> myList;

    for(int i = 0; i < 10; ++i)
    {
        myList.push_back(i);
    }

    for(list<int>::const_iterator iter = myList.begin(); iter != myList.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vector<int> myVector;
    copy(myList.begin(), myList.end(), back_inserter(myVector));

    for(vector<int>::const_iterator iter = myVector.begin(); iter != myVector.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    deque<int> myDeque;
    copy(myList.begin(), myList.end(), front_inserter(myDeque));

    for(deque<int>::const_iterator iter = myDeque.begin(); iter != myDeque.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    set<int> mySet;
    copy(myList.begin(), myList.end(), inserter(mySet, mySet.begin()));

    for(set<int>::const_iterator iter = mySet.begin(); iter != mySet.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

void myStream()
{
    vector<string> myVector;

    copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(myVector));

    sort(myVector.begin(), myVector.end());

    unique_copy(myVector.begin(), myVector.end(), ostream_iterator<string>(cout, "\n"));
}

void myReverse()
{
    vector<int> myVec;

    for(int i = 0; i < 10; ++i)
    {
        myVec.push_back(i);
    }

    for(vector<int>::const_iterator iter = myVec.begin(); iter != myVec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    //逆向遍历(方法不可取，看起来难懂，极易出错)
    cout << "逆向遍历: " << endl;
    for(vector<int>::const_iterator iter = --myVec.end(); iter != --myVec.begin(); --iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    //逆向遍历（可取）
    for(vector<int>::reverse_iterator reveIter = myVec.rbegin();
        reveIter != myVec.rend(); ++reveIter)
    {
        cout << *reveIter << " ";
    }
    cout << endl;

    copy(myVec.rbegin(), myVec.rend(), ostream_iterator<int>(cout , " "));
    cout << endl;

    //vector<int>::reverse_iterator reveIter = myVec.rbegin();
    //vector<int>::reverse_iterator reveIter1 = myVec.rend();

    //cout << *reveIter << endl;
    //cout << *reveIter1 << endl;
}

void myPointer()
{
    int *ptr = new int;

    int x = 10;

    *ptr = x;

    cout << *ptr << endl;

    *ptr = 11;

    cout << *ptr << endl;

    delete ptr;
}

void myDistance()
{
    list<int> myList;

    for(int i = -2; i < 9; ++i)
    {
        myList.push_back(i);
    }

    copy(myList.begin(), myList.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    list<int>::iterator pos;

    pos = find(myList.begin(), myList.end(), 2);
    if(pos != myList.end())
    {
        int dis;
        dis = distance(myList.begin(), pos);

        cout << dis << endl;
    }
}

int fun()
{
    //int *p = nullptr;
    int x = 10;

    //p = &x;

    return x;   //返回的临时变量是左值
}

void myVector()
{
    vector<int> myVec;

    for(int i = 0; i < 10; ++i)
    {
        myVec.push_back(i);
    }

    sort(++myVec.begin(), myVec.end());
}

int main()
{
    //myIterator();

    myStream();

    //myReverse();

    //myPointer();

    //myDistance();

    //myVector();

    //c++不允许任何修改基本类型(包括指针)临时值的行为，但对于类类型则允许
    //++fun();

    return 0;
}



/*
// istream_iterator example
#include <iostream>     // std::cin, std::cout
#include <iterator>     // std::istream_iterator

int main () {
  double value1, value2;
  std::cout << "Please, insert two values: ";

  std::istream_iterator<double> eos;              // end-of-stream iterator
  std::istream_iterator<double> iit (std::cin);   // stdin iterator

  if (iit!=eos) value1=*iit;

  ++iit;
  if (iit!=eos) value2=*iit;

  std::cout << value1 << "*" << value2 << "=" << (value1*value2) << '\n';

  return 0;
}
*/
