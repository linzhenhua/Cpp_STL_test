#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

void TestCopyOnWrite()
{
    string *str3 = new string("linzhenhua");

    cout << *str3 << endl;

    char s;

    cin >> s;

    string *str4 = str3;

    delete str3;

    cout << *str4 << endl;
}

void CopyOnWrite()
{
    string str1 = "hello world";
    string str2 = str1;

    printf ("Sharing the memory:\n");
    printf ("\tstr1's address: %x\n", str1.c_str() );
    printf ("\tstr2's address: %x\n", str2.c_str() );

    str1[1]='q';
    str2[1]='w';

    printf ("After Copy-On-Write:\n");
    printf ("\tstr1's address: %x\n", str1.c_str() );
    printf ("\tstr2's address: %x\n", str2.c_str() );
}

void String()
{
    string str("linzhenhua");

    cout << str << endl;
}

int main()
{
    //String();

    //CopyOnWrite();

    TestCopyOnWrite();

    return 0;
}
