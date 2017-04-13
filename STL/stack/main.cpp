#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void Stack()
{
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout << "size: " << st.size() << endl;

    cout << st.top() << endl;

    while( !st.empty() )
    {
        cout << st.top() << endl;
        st.pop();
    }

    cout << st.size() << endl;
}

int main()
{
    Stack();

    return 0;
}
