#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iomanip>

using namespace std;

/*
//map�������key����ģ�����key��ʲô���ͣ��ȽϺ�������ʲô����
bool fncomp(const int& lhs, const int& rhs)
{
    return lhs > rhs;
}

//�º���
class ClassComp{
public:
    bool operator() (const int &lhs, const int &rhs) const
    {
        return lhs > rhs;
    }
};


void myMap1()
{
    map<int, string> myMap1;
    myMap1[1] = "lin";
    myMap1[2] = "zhen";
    myMap1[3] = "hua";
    for(map<int, string>::iterator iter = myMap1.begin(); iter != myMap1.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;

    map<int, string> myMap2(myMap1);     //���ƹ��캯��
    for(map<int, string>::iterator iter = myMap2.begin(); iter != myMap2.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;

    map<int, string> myMap3(myMap2.begin(), myMap2.end());
    for(map<int, string>::iterator iter = myMap3.begin(); iter != myMap3.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;

    map<int, string, ClassComp> myMap4(myMap3.begin(), myMap3.end());
    for(map<int, string>::iterator iter = myMap4.begin(); iter != myMap4.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;

    pair<int, string> myPair;
    myPair = make_pair(1, "lin");

    map<int, string> myMap5;
    myMap5.insert(myPair);
    for(map<int, string>::iterator iter = myMap5.begin(); iter != myMap5.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;

    bool (*ptrFncomp)(const int&, const int&) = fncomp;
    typedef map<int, string, bool (*)(const int&, const int&)> intMap;
    intMap myMap6(myMap4.begin(), myMap4.end(), ptrFncomp);
    for(map<int, string>::iterator iter = myMap6.begin(); iter != myMap6.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;
}

void myMap2()
{
    map<int, string> myMap1;
    myMap1[1] = "lin";
    myMap1[2] = "zhen";
    myMap1[3] = "hua";

    for(map<int, string>::iterator iter = myMap1.begin(); iter != myMap1.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;

    //myMap1[3] = "cpp";

    pair<int, string> myPair;
    myPair = make_pair(4, "cpp");

    pair< map<int, string>::iterator, bool > ret;   //����ֵ
    ret = myMap1.insert(myPair);

    if(ret.second == true)
    {
        for(map<int, string>::iterator iter = myMap1.begin(); iter != myMap1.end(); ++iter)
        {
            cout << iter->first << " " << iter->second << endl;
        }
        cout << endl;
    }

    myMap1[5] = "c++";

    for(map<int, string>::iterator iter = myMap1.begin(); iter != myMap1.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;

    //��ı�myMap[4] = "cpp"��key����4Ԫ��ɾ����Ȼ����myMap��ֵ��cpp�����²��룬
    //�����Ϳ����ڲ��ı�value��ֵ������£��ı�key
    //eg: �ı�myMap[4] = "cpp"ΪmyMap[6] = "cpp"
    map<int, string>::iterator iter = myMap1.find(4);
    if(iter != myMap1.end())
    {
        myMap1.insert(map<int, string>::value_type(6,iter->second));
        myMap1.erase(iter);
    }

    for(map<int, string>::iterator iter = myMap1.begin(); iter != myMap1.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;

    myMap1.erase(6);

    for(map<int, string>::iterator iter = myMap1.begin(); iter != myMap1.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;
}

*/

//ʵ������map��������ʽ����
//������ӳ��Ʊ����
void stock()
{
    typedef map<string, float> StringFloatMap;
    StringFloatMap stocks;

    stocks["BASF"] = 369.50;
    stocks["VW"] = 413.50;
    stocks["Daimler"] = 819.00;
    stocks["BMW"] = 834.00;
    stocks["Siemens"] = 842.20;

    for(StringFloatMap::iterator iter = stocks.begin(); iter != stocks.end(); ++iter)
    {
        cout << "stock[" << iter->first << "] =\t" << iter->second << endl;
    }
    cout << endl;

    //�Ǽ�
    for(StringFloatMap::iterator iter = stocks.begin(); iter != stocks.end(); ++iter)
    {
        iter->second *= 2.0;
    }

    for(StringFloatMap::iterator iter = stocks.begin(); iter != stocks.end(); ++iter)
    {
        cout << "stock[" << iter->first << "] =\t" << iter->second << endl;
    }
    cout << endl;

    stocks["Volkswagen"] = stocks["VW"];
    stocks.erase("VW");
    //StringFloatMap::iterator iter = stocks.find("VW");
    //stocks.erase(iter);

    for(StringFloatMap::iterator iter = stocks.begin(); iter != stocks.end(); ++iter)
    {
        cout << "stock[" << iter->first << "] =\t" << iter->second << endl;
    }
    cout << endl;
}

//��map�����ֵ�
void dict()
{
    typedef multimap<string, string> StrStrMap;

    StrStrMap dict;

    dict.insert(make_pair("day", "Tag"));
    dict.insert(make_pair("strange", "fremd"));
    dict.insert(make_pair("car", "Auto"));
    dict.insert(make_pair("smart", "elegant"));
    dict.insert(make_pair("trait", "Merkmal"));
    dict.insert(make_pair("strange", "seltsam"));
    dict.insert(make_pair("smart", "raffiniert"));
    dict.insert(make_pair("smart", "klug"));
    dict.insert(make_pair("clever", "raffiniert"));

    StrStrMap::iterator pos;

    cout.setf(ios::left, ios::adjustfield);
    cout << ' ' << setw(10) << "english " << "german " << endl;

    cout << setfill('-') << setw(20) << "" << setfill(' ') << endl;

    for(pos = dict.begin(); pos != dict.end(); ++pos)
    {
        cout << ' ' << setw(10) << pos->first.c_str() << pos->second << endl;
    }
    cout << endl;

    string word("smart");

    cout << word << ": " << endl;
    for(pos = dict.lower_bound(word); pos != dict.upper_bound(word); ++pos)
    {
        cout << "     " << pos->second << endl;
    }

    word = "raffiniert";
    cout << word << ": " << endl;
    for(pos = dict.begin(); pos != dict.end(); ++pos)
    {
        if(pos->second == word)
        {
            cout << "     " << pos->first << endl;
        }
    }
}

int main()
{
    //myMap1();

    //myMap2();

    //stock();

    dict();

    return 0;
}
