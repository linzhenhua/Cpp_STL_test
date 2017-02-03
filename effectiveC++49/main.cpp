#include <iostream>
#include <new>
#include <cstdlib>

using namespace std;

void myOutOfMemory()      //·ÖÅäÄÚ´æ
{
    cout << "Out Of Memory" << endl;
    abort();
}

int main()
{
    set_new_handler(myOutOfMemory);

    char* p = new char [1024*1024];

    delete []p;

    return 0;
}
