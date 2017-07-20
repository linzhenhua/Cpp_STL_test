#include <string.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

void myIosteam1()
{
    stringstream i;

    cout << i.good() << "\t" << i.bad() << '\t' << i.eof() << '\t' << i.fail() << '\n';
    cout << i.rdstate() << endl;
}

void myIosteam2()
{
    char str[5];

    cin >> str;

    //cin.get(str, 5);
    //cin >> str;
    //cin.get(str, 5, '8');
    //cin.getline(str, 5, '2');

    cout << str << endl;
}

void myOstream1()
{
    char str = 'a';

    cout.put(str);
}

void myOstream2()
{
    bool a;

    cout << std::noboolalpha << a << "==" << std::boolalpha << a << endl;

    cout << std::oct << 10 << std::hex << 10 << endl;

    cout.unsetf(std::ios::oct);
    //cout.setf(std::ios::hex);

    cout << 11 << endl;

    cout.unsetf(std::ios::hex);

    cout << 10.3366 << endl;
}

void myFileOpt()
{
    //定义一个文件类对象
    fstream File;

    //打开文件
    File.open("test.txt", ios::in | ios::out | ios::binary | ios::app);

    //判断是否打开成功
    if(!File)
    {
        cout << "open file error" << endl;

        return ;
    }

    //写文件
    string name = "linzhenhua";

    //cout << sizeof(name) << endl;

    File.write(name.c_str(), name.length());

    //读文件
    char str[100] = {0};

    //先获取文件的长度
    File.seekg(0, File.end);
    int length = File.tellg();
    File.seekg(0, File.beg);

    File.read(str, length);

    cout << str << endl;

    //关闭文件
    File.close();
}

int main(int argc, char *argv[])
{
    //myIosteam1();

    //myIosteam2();

    //myOstream1();

    //myOstream2();

    myFileOpt();

    return 0;
}
