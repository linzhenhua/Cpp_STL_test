#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void myList()
{
    list<int> myList;

    for(int i = 0; i < 20; ++i)
    {
        myList.push_back(i);
    }

    for(list<int>::const_iterator iter = myList.begin(); iter != myList.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    list<int>::iterator pos;

    pos = find(myList.begin(), myList.end(), 5);
    cout << *pos << endl;

    reverse(pos, myList.end());

    for(list<int>::const_iterator iter = myList.begin(); iter != myList.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    //�㷨����������pos1֮��Ѱ�ң����û���ҵ�������pos1֮��Ѱ��
    list<int>::iterator pos1, pos2;

    pos1 = find(myList.begin(), myList.end(), 13);
    cout << "pos1: " << *pos1 << endl;
    //���pos2==pos1��ʾpos2��pos1ͬһλ�û�����pos1����
    pos2 = find(myList.begin(), pos1, 11);
    cout << "pos2: " << *pos2 << endl;

    if(pos1 != pos2)
    {
        //pos2 is front of pos1 [pos2, pos1)
        cout << "pos1 is front of pos2 [pos2, pos1): " << *max_element(pos2, ++pos1) << endl;
    }
    else
    {
        pos2 = find(pos1, myList.end(), 10);
        if(pos1 != pos2)
        {
            //pos2 is front of pos1 [pos2, pos1)
            cout << "pos1 is front of pos2 [pos1, pos2): " << *max_element(pos1, ++pos2) << endl;
        }
        else
        {
            cout << "both are equal" << endl;
        }
    }

    /*
    pos2 ��ǰ pos1 ���δֵ֪
    cout << *max_element(pos1, ++pos2) << endl;

    if(pos1 == pos2)
    {
        list<int>::iterator pos3;
        pos3 = max_element(pos1, ++pos2);
        cout << "pos3: " << *pos3 << endl;
    }
    */
}

int main()
{
    myList();

    return 0;
}
