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
#include <stdexcept>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

/*
void myVector()
{
    vector<int> vec;

    for(int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }

    cout << vec.size() << endl;

    //ͨ������������
    for(vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << endl;

    //ͨ���±����
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

    //ͨ������������
    for(deque<float>::const_iterator iter = deq.begin(); iter != deq.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << endl;

    //ͨ���±����
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

    //ͨ������������,ע�ⲻ֧���±����
    for(list<char>::const_iterator iter = ch.begin(); iter != ch.end(); ++iter)
    {
        cout << *iter << " ";
     // *iter = 1;    error
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

    //����ķ�ʽ
    //for(size_t i = 0; i < mySet.size(); ++i)
    //{
    //    cout << mySet[i] << " ";
    //}

    cout << endl;
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

    //����ķ�ʽ
    //for(size_t i = 0; i < myMultiset.size(); ++i)
    //{
    //    cout << myMultiset[i] << " ";
    //}

    cout << endl;
}

void myMap()
{
    map<int,string> myMap;

    //pair<int,string> myPair1;
    //pair<int,string> myPair2;
    //pair<int,string> myPair3;
    //pair<int,string> myPair4;

    //myPair1 = make_pair(1,"lin");
    //myPair2 = make_pair(2,"zhen");
    //myPair3 = make_pair(3,"hua");
    //myPair4 = make_pair(4,"Cpp");

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

    //pair<int,string> myPair1;
    //pair<int,string> myPair2;
    //pair<int,string> myPair3;
    //pair<int,string> myPair4;

    //myPair1 = make_pair(1,"lin");
    //myPair2 = make_pair(2,"zhen");
    //myPair3 = make_pair(3,"hua");
    //myPair4 = make_pair(4,"Cpp");

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

    //����ķ�ʽ
    //for(size_t i = 0; i < myMultimap.size(); ++i)
    //{
    //    cout << myMultimap[i] << " ";
    //}

    cout << endl;
}

void myStack()
{
    stack<int> myStack;

    for(int i = 0; i < 10; ++i)
    {
        myStack.push(i);
    }

    //for(int i = 0; i < myStack.size(); ++i) ����ı�����ʽ����Ϊsize��С���
    while( !myStack.empty() )
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    cout << endl;

    //����������������֧�ֵ�����
    //for(stack<int>::iterator iter = myStack.begin(); iter != myStack.end(); ++iter)
    //{
    //    cout << *iter << " ";
    //}

    cout << endl;
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

    //���캯��  begin

    vector<int> vec1;
    //copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
    //cout << endl;

    vector<int> vec2(2);
    //copy(vec2.begin(), vec2.end(), ostream_iterator<int>(cout, " "));
    //cout << endl;

    vector<int> vec3(2,10);
    //copy(vec3.begin(), vec3.end(), ostream_iterator<int>(cout, " "));
    //cout << endl;

    vector<int> vec4(vec3);
    //copy(vec4.begin(), vec4.end(), ostream_iterator<int>(cout, " "));
    //cout << endl;

    int arr[2] = {1,2};
    vector<int> vec5(arr, arr + sizeof(arr)/sizeof(int));
    //copy(vec5.begin(), vec5.end(), ostream_iterator<int>(cout, " "));
    //cout << endl;

    //���캯�� end

    //�Ǳ䶯�Բ��� begin

    vector<int> vec6;
    for(int i = 0; i < 10; ++i)
    {
        vec6.push_back(i);
    }
    //copy(vec6.begin(), vec6.end(), ostream_iterator<int>(cout, " "));
    //cout << endl;

    //cout << "size: " << vec6.size() << endl;
    //cout << "is empty: " << vec6.empty() << endl;
    //cout << "max_size: " << vec6.max_size() << endl;
    //cout << "capacity: " << vec6.capacity() << endl;

    //�Ǳ䶯�Բ���  end

    //��ֵ begin

    vector<int> vec7;

    vec7.assign(arr, arr+sizeof(arr)/sizeof(int));
    //copy(vec7.begin(), vec7.end(), ostream_iterator<int>(cout, " "));
    //cout << endl;

    vector<int> vec8 = vec7;
    //copy(vec8.begin(), vec8.end(), ostream_iterator<int>(cout, " "));
    //cout << endl;

    vec8.assign(10,3);
    //copy(vec8.begin(), vec8.end(), ostream_iterator<int>(cout, " "));
    //cout << endl;

    //vec7.swap(vec8);
    //copy(vec7.begin(), vec7.end(), ostream_iterator<int>(cout, " "));
    //cout << endl;
    //copy(vec8.begin(), vec8.end(), ostream_iterator<int>(cout, " "));
    //cout << endl;

    //swap(vec7,vec8);
    //copy(vec7.begin(), vec7.end(), ostream_iterator<int>(cout, " "));
    //cout << endl;
    //copy(vec8.begin(), vec8.end(), ostream_iterator<int>(cout, " "));
    //cout << endl;

    vec7.assign(vec8.begin(), vec8.end());
    //copy(vec7.begin(), vec7.end(), ostream_iterator<int>(cout, " "));
    //cout << endl;

    //��ֵ end

    //Ԫ�ش�ȡ begin

    vector<int> vec9(10);

    copy(vec9.begin(), vec9.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for(int i = 0; i < 10; ++i)
    {
        vec9.at(i) = i;
    }
    copy(vec9.begin(), vec9.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //����at����Խ��
    try{
        cout << vec9.at(9) << endl;
        //vec9[110] = 11;              //�±�Խ�磬ע��
    }catch(const exception& error){
        cerr << error.what() << endl;
        return;
    }

    //���ж�at���������Ƿ�Խ��
    if(vec9.size() > 9)
    {
        cout << vec9.at(9) << endl;
    }
    if(!vec9.empty())
    {
        cout << vec9.front() << endl;
        cout << vec9.back() << endl;
    }

    //��ȫ�����Ҫ��������Ƿ�Ϊ��
    //cout << vec9.front() << endl;
    //cout << vec9.back() << endl;

    //Ԫ�ش�ȡ end
}
*/

void vector_operator2()
{
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    vector<int> vec1(arr, arr+sizeof(arr)/sizeof(int));

    //��������غ��� begin

    for(vector<int>::const_iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    //ע����������Ͳ���const_iterator������reverse_iterator
    for(vector<int>::reverse_iterator iter = vec1.rbegin(); iter != vec1.rend(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    //��������غ��� end

    //������Ƴ�Ԫ�� begin

    vec1.insert(vec1.begin(), 0);
    for(vector<int>::const_iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vec1.insert(vec1.end(), 10);
    for(vector<int>::const_iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vec1.insert(vec1.end(),2,10);
    for(vector<int>::const_iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vec1.pop_back();
    for(vector<int>::const_iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vec1.erase(--vec1.end());
    for(vector<int>::const_iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vec1.erase(vec1.begin()+9, vec1.end());
    for(vector<int>::const_iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vec1.resize(5);
    for(vector<int>::const_iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vec1.clear();
    for(vector<int>::const_iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << vec1.size() << endl;       //��ǰ��Ŷ��ٸ�Ԫ��
    cout << vec1.capacity() << endl;   //�������capacity�����������·����ڴ�
    cout << endl;

    //������Ƴ�Ԫ�� end
}

//�º���
class SameElem{
public:
    bool operator()(int x) const
    {
        if(x == 5)
            return true;
        else
            return false;
    }
};

//���ʣ���vector�����ɾ����ĳֵ��ͬ��Ԫ��
void del_elem(int elem)
{
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    vector<int> vec1(arr, arr+sizeof(arr)/sizeof(int));
    //vec1.push_back(5);

    for(vector<int>::const_iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    //ֻ��ɾ����һ�����ֵ�Ԫ��
    vector<int>::iterator iter;
    iter = find(vec1.begin(), vec1.end(), elem);
    if(iter != vec1.end())        //һ��Ҫ�����ж���������Ȼ������ܻ����
        vec1.erase(iter);

    for(vector<int>::const_iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    //���Ҫɾ��һ��������������ͬ��Ԫ��
    vec1.erase(remove(vec1.begin(), vec1.end(), elem), vec1.end());

    for(vector<int>::const_iterator iter = vec1.begin(); iter != vec1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vector<char> vec2;
    vec2.resize(41);
    strcpy(&vec2[0], "hello, world");
    printf("%s\n", &vec2[0]);
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

    //vector_operator1();

    //vector_operator2();

    del_elem(15);

    return 0;
}
