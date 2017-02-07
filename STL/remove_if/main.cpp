#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

void myVec()
{
    vector<int> vec;

    for(int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int>::iterator iter;
    iter = remove_if(vec.begin(), vec.end(), bind2nd(less<int>(), 5));

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vec.erase(iter, vec.end());

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    myVec();

    return 0;
}
