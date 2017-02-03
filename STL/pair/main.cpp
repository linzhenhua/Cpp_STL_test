#include <iostream>
#include <utility>
#include <string>

using namespace std;

int main()
{
    pair<int, string> mypair;
    pair<int, string> mypair1;

    mypair = make_pair(10, "mypair");
    mypair1 = make_pair(9, "mypair1");

    mypair = mypair1;

    cout << mypair.first << " " << mypair.second << endl;

    if(mypair == mypair1)
    {
        cout << "mypair == mypair1" << endl;
    }
    else if(mypair > mypair1)
    {
        cout << "mypair > mypair1" << endl;
    }
    else if(mypair < mypair1)
    {
        cout << "mypair < mypair1" << endl;
    }

    return 0;
}
