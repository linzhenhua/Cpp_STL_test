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
    //����һ���ļ������
    fstream File;

    //���ļ�
    File.open("test.txt", ios::in | ios::out | ios::binary | ios::app);

    //�ж��Ƿ�򿪳ɹ�
    if(!File)
    {
        cout << "open file error" << endl;

        return ;
    }

    //д�ļ�
    string name = "linzhenhua";

    //cout << sizeof(name) << endl;

    File.write(name.c_str(), name.length());

    //���ļ�
    char str[100] = {0};

    //�Ȼ�ȡ�ļ��ĳ���
    File.seekg(0, File.end);
    int length = File.tellg();
    File.seekg(0, File.beg);

    File.read(str, length);

    cout << str << endl;

    //�ر��ļ�
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
