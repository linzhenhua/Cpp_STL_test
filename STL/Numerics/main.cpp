#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>

using namespace std;

void Complex()
{
    complex<int> first(1,2);
    complex<int> second(3,4);

    cout << first << endl;
    cout << first.real() << endl;
    cout << first + second << endl;

    //cin >> first;
    //cout << first << endl;

    complex<int> third( conj(second) );
    cout << third << endl;
}

int main()
{
    Complex();

    return 0;
}
