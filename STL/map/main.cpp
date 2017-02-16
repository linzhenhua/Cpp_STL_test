#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iomanip>
#include <cctype>

using namespace std;

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

//�º���
template<class K, class V>
class Value_equals{
private:
    V value;

public:
    Value_equals(const V& v):value(v){}

    bool operator() (pair<const K, V> elem) const
    {
        return elem.second == value;
    }
};

//��Ѱ����ĳ�ض�ʵֵ��Ԫ��
void mySearch()
{
    typedef map<float, float> FloatFloatMap;
    FloatFloatMap coll;
    FloatFloatMap::iterator pos;

    coll.insert(make_pair(1, 7));
    coll.insert(make_pair(2, 4));
    coll.insert(make_pair(3, 2));
    coll.insert(make_pair(4, 3));
    coll.insert(make_pair(5, 6));
    coll.insert(make_pair(6, 1));
    coll.insert(make_pair(7, 3));

    pos = coll.find(3.0);
    if(pos != coll.end())
    {
        cout << pos->first << ": " << pos->second << endl;
    }

    pos = find_if(coll.begin(), coll.end(), Value_equals<float, float>(3.0));
    if(pos != coll.end())
    {
        cout << pos->first << ": " << pos->second << endl;
    }
}

class RuntimeStringCmp{
public:
    enum cmp_mode{normal, nocase};   //0,1

private:
    //Ϊʲôconst������ʼ�����ø�ֵ����Ϊ��������ĳ�ʼ���б����ʼ��
    const cmp_mode mode;

    static bool nocase_compare(char c1, char c2)
    {
        return toupper(c1) < toupper(c2);    //toupper()������Сд��ĸ��ɴ�д��ĸ
    }

public:
    RuntimeStringCmp(cmp_mode m = normal):mode(m){}

    bool operator()(const string& s1, const string& s2) const
    {
        if(mode == normal)
        {
            return s1 < s2;
        }
        else
        {
            return lexicographical_compare(s1.begin(), s1.end(),
                                            s2.begin(), s2.end(),
                                            nocase_compare);
        }
    }
};

typedef map<string, string, RuntimeStringCmp> StringStringMap;

void fillAndPrint(StringStringMap& coll)
{
    coll["Deutschland"] = "Germany";
    coll["deutsch"] = "German";
    coll["Haken"] = "snag";
    coll["arbeiten"] = "work";
    coll["Hund"] = "dog";
    coll["gehen"] = "go";
    coll["Unternehmen"] = "enterprise";
    coll["unternehmen"] = "undertake";
    coll["gehen"] = "walk";
    coll["Bestatter"] = "undertaker";

    StringStringMap::iterator pos;

    cout.setf(ios::left, ios::adjustfield);
    for(pos = coll.begin(); pos != coll.end(); ++pos)
    {
        cout << setw(15) << pos->first.c_str() << " " << pos->second << endl;
    }
    cout << endl;
}

//map���ۺ�����
void myMap3()
{
    StringStringMap coll1;
    fillAndPrint(coll1);

    RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);

    StringStringMap coll2(ignorecase);

    fillAndPrint(coll2);
}

int main()
{
    //myMap1();

    //myMap2();

    //stock();

    //dict();

    //mySearch();

    myMap3();

    return 0;
}
