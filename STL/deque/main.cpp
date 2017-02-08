#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

void myDequeInit()
{
    //构造函数 begin
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    deque<int> deq1;
    copy(deq1.begin(), deq1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    deque<int> deq2(arr, arr+sizeof(arr)/sizeof(int));
    copy(deq2.begin(), deq2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    deque<int> deq3(deq2);
    copy(deq3.begin(), deq3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    deque<int> deq4(10);
    copy(deq4.begin(), deq4.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    deque<int> deq5(deq2.begin(), deq2.end());
    copy(deq5.begin(), deq5.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //构造函数 end
}

void myDeque1()
{
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    deque<int> deq1(arr, arr+sizeof(arr)/sizeof(int));

    cout << "size: " << deq1.size() << endl;
    cout << "is empty: " << deq1.empty() << endl;
    cout << "max_size: " << deq1.max_size() << endl;
    //cout << "capacity: " << deq1.capacity() << endl;
}

int main()
{
    //myDequeInit();

    myDeque1();

    return 0;
}
