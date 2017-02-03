/*
// numeric_limits example
#include <iostream>     // std::cout
#include <limits>       // std::numeric_limits

int main ()
{
  std::cout << std::boolalpha;
  std::cout << "Minimum value for int: " << std::numeric_limits<int>::min() << '\n';
  std::cout << "Maximum value for int: " << std::numeric_limits<int>::max() << '\n';
  std::cout << "int is signed: " << std::numeric_limits<int>::is_signed << '\n';
  std::cout << "Non-sign bits in int: " << std::numeric_limits<int>::digits << '\n';
  std::cout << "int has infinity: " << std::numeric_limits<int>::has_infinity << '\n';

  return 0;
}
*/

#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int *x, int *y)
{
    return *x > *y;
}

int main()
{
    int x = 10;
    int y = 11;

    int *ptr1 = &x;
    int *ptr2 = &y;

    cout << max(ptr1, ptr2, compare) << endl;

    return 0;
}
