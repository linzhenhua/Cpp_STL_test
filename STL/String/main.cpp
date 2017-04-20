#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>

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

    string str7("There are two needles two in this haystack with needles.");

    size_t found1 = str7.find("two", 0);
    if(found1 != string::npos)
    {
        cout << found1 << endl;
    }

    size_t found2 = str7.find("twq", found1+1, 2);
    if(found2 != string::npos)
    {
        cout << found2 << endl;
    }

    size_t found3 = str7.rfind("two");
    if(found3 != string::npos)
    {
        cout << found3 << endl;
    }

    size_t found4 = str7.find_first_of("are");   //find_first_of()查找“are”中出现的第一个
    if(found4 != string::npos)
    {
        cout << found4 << endl;
    }

    string str8("lin");
    string str9("zhen");

    string str10 = str8 + str9;
    cout << str10 << endl;

    str10.append("hua");
    cout << str10 << endl;

    str10.insert(10, " is a C++ programer");
    cout << str10 << endl;

    str10.assign("hello");
    cout << str10 << endl;
}

void Equal()
{
    string str11("linzhenhua");
    string str12("linzhenhuai");

    bool flag = equal( str11.begin(), str11.end(), str12.begin() );
    cout << flag << endl;

    //cout << (str11 == str12) << endl;

    int ch[] = {1,2,3,4,5};
    vector<int> vec1(ch, ch+2);
    vector<int> vec2(ch, ch+1);

    flag = equal( vec1.begin(), vec1.end(), vec2.begin() );
    cout << flag << endl;
}

int main()
{
    String();

    //CopyOnWrite();

    //TestCopyOnWrite();

    Equal();

    return 0;
}
