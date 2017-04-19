#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

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

    //第一次修改的会CopyOnWrite一份出来
    str1[1]='q';
    str2[1]='w';

    printf ("After Copy-On-Write:\n");
    printf ("\tstr1's address: %x\n", str1.c_str() );
    printf ("\tstr2's address: %x\n", str2.c_str() );
}

void String()
{
    //只有在单参数版本中，才将char*字符'\0'当做字符串结尾特殊符号来处理
    const char *ch = "aa\0bb";
    string str1(ch, 5);
    cout << str1 << endl;

    const char *ch1 = "linzhenhua";
    string str2(ch1);
    cout << str2 << endl;

    string str3(str2, 3, 4);
    cout << str3 << endl;

    string str4(str2.begin(), str2.end());
    cout << str4 << endl;

    const char* ch2 = str4.c_str();
    //要使ch2不失效，要复制一份出来给ch2，用strcpy
    //const char* ch2 = new char[str4.length()+1];
    //strcpy(ch2, str4.c_str());
    //delete []ch2;
    cout << ch2 << endl;
    str4 = "lllllll";
    cout << ch2 << endl;
    cout << str4 << endl;

    cout << str4.size() << " " << str4.length() << endl;
    cout << str4.capacity() << endl;
    cout << str4.max_size() << endl;

    string str5("guangzhou");
    //str5.reserve(80);
    cout << str5.size() << " " << str5.length() << endl;
    cout << str5.capacity() << endl;
    cout << str5.max_size() << endl;
    cout << str5[2] << endl;
    cout << str5.at(8) << endl;
    str5.at(0) = 'o';           //???
    str5[1] = 'o';
    cout << str5 << endl;

    string str6 = "shenzhen";

    str5.swap(str6);
    cout << str5 << " " << str6 << endl;





}

int main()
{
    String();

    //CopyOnWrite();

    //TestCopyOnWrite();

    return 0;
}
