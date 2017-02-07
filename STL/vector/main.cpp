#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <iterator>

using namespace std;

void myVector()
{
    vector<int> vec;

    for(int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }

    cout << vec.size() << endl;

    //通过迭代器遍历
    for(vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << endl;

    //通过下标遍历
    for(size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }

    cout << endl;
}

void myDeque()
{
    deque<float> deq;

    for(int i = 1; i < 10; ++i)
    {
        //deq.push_front(i*0.1);
        deq.push_back(i*0.1);
    }

    //通过迭代器遍历
    for(deque<float>::const_iterator iter = deq.begin(); iter != deq.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << endl;

    //通过下标遍历
    for(size_t i = 0; i < deq.size(); ++i)
    {
        cout << deq[i] << " ";
    }

    cout << endl;
}

void myList()
{
    list<char> ch;

    for(char i = 'a'; i <= 'z'; ++i)
    {
        ch.push_back(i);
    }

    //通过迭代器遍历,注意不支持下标遍历
    for(list<char>::const_iterator iter = ch.begin(); iter != ch.end(); ++iter)
    {
        cout << *iter << " ";
        //*iter = 1;    errror
    }

    cout << endl;
}

void mySet()
{
    int myArray[] = {1,2,3,4,5,6,7,9,8,11,10};
    set<int> mySet(myArray, myArray+11);

    for(set<int>::const_iterator iter = mySet.begin(); iter != mySet.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << endl;

    mySet.insert(0);

    for(set<int>::const_iterator iter = mySet.begin(); iter != mySet.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << endl;

    /*
    for(size_t i = 0; i < mySet.size(); ++i)
    {
        cout << mySet[i] << " ";
    }

    cout << endl;
    */
}

void myMultiset()
{
    int myArray[] = {1,2,2,4,5,5,7,9,8,11,11};
    multiset<int> myMultiset(myArray, myArray+11);

    for(set<int>::const_iterator iter = myMultiset.begin(); iter != myMultiset.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << endl;

    myMultiset.insert(0);

    for(set<int>::const_iterator iter = myMultiset.begin(); iter != myMultiset.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << endl;

    /*
    for(size_t i = 0; i < myMultiset.size(); ++i)
    {
        cout << myMultiset[i] << " ";
    }

    cout << endl;
    */
}

void myMap()
{
    map<int,string> myMap;
/*
    pair<int,string> myPair1;
    pair<int,string> myPair2;
    pair<int,string> myPair3;
    pair<int,string> myPair4;

    myPair1 = make_pair(1,"lin");
    myPair2 = make_pair(2,"zhen");
    myPair3 = make_pair(3,"hua");
    myPair4 = make_pair(4,"Cpp");
*/
    myMap.insert(make_pair(1,"lin"));
    myMap.insert(make_pair(2,"zhen"));
    myMap.insert(make_pair(3,"hua"));
    myMap.insert(make_pair(4,"Cpp"));

    for(map<int,string>::const_iterator iter = myMap.begin(); iter != myMap.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }

    cout << endl;

    for(size_t i = 0; i < myMap.size(); ++i)
    {
        cout << myMap[i] << " ";
    }

    cout << endl;
}

void myMultimap()
{
    multimap<int,string> myMultimap;
/*
    pair<int,string> myPair1;
    pair<int,string> myPair2;
    pair<int,string> myPair3;
    pair<int,string> myPair4;

    myPair1 = make_pair(1,"lin");
    myPair2 = make_pair(2,"zhen");
    myPair3 = make_pair(3,"hua");
    myPair4 = make_pair(4,"Cpp");
*/
    myMultimap.insert(make_pair(1,"lin"));
    myMultimap.insert(make_pair(1,"lin"));
    myMultimap.insert(make_pair(2,"zhen"));
    myMultimap.insert(make_pair(2,"zhen"));
    myMultimap.insert(make_pair(3,"hua"));
    myMultimap.insert(make_pair(4,"Cpp"));

    for(multimap<int,string>::const_iterator iter = myMultimap.begin(); iter != myMultimap.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }

    cout << endl;

    /*
    for(size_t i = 0; i < myMultimap.size(); ++i)
    {
        cout << myMultimap[i] << " ";
    }

    cout << endl;
    */
}

void myStack()
{
    stack<int> myStack;

    for(int i = 0; i < 10; ++i)
    {
        myStack.push(i);
    }

    //for(int i = 0; i < myStack.size(); ++i) 错误的遍历方式，因为size大小会变
    while( !myStack.empty() )
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    cout << endl;

    //错误，容器适配器不支持迭代器
    /*
    for(stack<int>::iterator iter = myStack.begin(); iter != myStack.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << endl;
    */
}

void myQueue()
{
    queue<int> myQueue;

    for(int i = 0; i < 10; ++i)
    {
        myQueue.push(i);
    }

    while(!myQueue.empty())
    {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }

    cout << endl;
}

void myPriorityQueue()
{
    priority_queue<int> myPriorityQueue;

    for(int i = 0; i < 10; ++i)
    {
        myPriorityQueue.push(i);
        //myPriorityQueue.push(1);
    }

    while(!myPriorityQueue.empty())
    {
        cout << myPriorityQueue.top() << " ";
        myPriorityQueue.pop();
    }

    cout << endl;
}

void vector_operator()
{

    vector<int> vec;

    cout << "size: " << vec.size() << endl;
    cout << "is empty: " << vec.empty() << endl;
    cout << "max_size: " << vec.max_size() << endl;
    cout << "capacity: " << vec.capacity() << endl;

    cout << endl;

    vector<int> vec1;

    vec1.reserve(12);

    for(int i = 0; i < 5; ++i)
    {
        vec1.push_back(i);
    }

    cout << "size: " << vec1.size() << endl;
    cout << "is empty: " << vec1.empty() << endl;
    cout << "max_size: " << vec1.max_size() << endl;
    cout << "capacity: " << vec1.capacity() << endl;

    vector<int>::iterator iter = vec1.begin();
    cout << *iter << endl;

    int arr[10] = {9,8,7,6,5,4,3,2,1,0};

    //vec1.assign(arr, sizeof(arr)/sizeof(int));
    cout << "sizeof(arr)/sizeof(int): " << sizeof(arr)/sizeof(int) << endl;

    vec1.assign(arr, arr+9);

    copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //vec1.erase(iter);
    //vec1.erase(iter);
    vec1.insert(iter, 1000);

    cout << "size: " << vec1.size() << endl;
    cout << "is empty: " << vec1.empty() << endl;
    cout << "max_size: " << vec1.max_size() << endl;
    cout << "capacity: " << vec1.capacity() << endl;

    copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << *iter << endl;
}

void vector_operator1()
{
    vector<int> vec1;
    vector<int> vec2(2);
    vector<int> vec3(2,10);
}

int main()
{
    //myVector();

    //myDeque();

    //myList();

    //mySet();

    //myMultiset();

    //myMap();

    //myMultimap();

    //myStack();

    //myQueue();

    //myPriorityQueue();

    //vector_operator();

    vector_operator1();

    return 0;
}
