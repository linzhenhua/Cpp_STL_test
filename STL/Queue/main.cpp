#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

void Queue()
{
    queue<int> que;

    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);

    cout << que.size() << endl;

    cout << que.front() << endl;

    cout << que.back() << endl;

    while( !que.empty() )
    {
        cout << que.front() << endl;
        que.pop();
    }
}

void PriorityQueue()
{
    priority_queue<int> pri_queue;

    pri_queue.push(1);
    pri_queue.push(2);
    pri_queue.push(3);
    pri_queue.push(4);
    pri_queue.push(5);

    cout << pri_queue.size() << endl;

    cout << pri_queue.top() << endl;
    pri_queue.pop();
    cout << pri_queue.top() << endl;

    while( !pri_queue.empty() )
    {
        cout << pri_queue.top() << endl;
        pri_queue.pop();
    }
}

int main()
{
    //Queue();

    PriorityQueue();

    return 0;
}
