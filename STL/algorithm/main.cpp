#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void myRemove()
{
    vector<int> myVec;

    for(int i = 0; i != 10; ++i)
    {
        myVec.push_back(i);
    }

    for(vector<int>::const_iterator iter = myVec.begin(); iter != myVec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vector<int>::iterator removeIter;
    removeIter = remove(myVec.begin(), myVec.end(), 8);
    //remove(myVec.begin(), myVec.end(), 7);
    //remove(myVec.begin(), myVec.end(), 1);

    for(vector<int>::const_iterator iter = myVec.begin(); iter != myVec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vector<int>::iterator findIter;
    findIter = find(myVec.begin(), myVec.end(), 2);
    myVec.erase(findIter, myVec.end());
/*
    vector<int>::iterator tempIter = myVec.erase(findIter, findIter+2);

    cout << *tempIter << endl;
*/
    for(vector<int>::const_iterator iter = myVec.begin(); iter != myVec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

void myAlgorithm()
{
    vector<int> vec;

    //����Ԫ��
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(9);
    vec.push_back(8);

    //����
    for(vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vector<int>::iterator pos;

    //��Сֵ
    pos = min_element(vec.begin(), vec.end());
    cout << "min elem: " << *pos << endl;

    //���ֵ
    pos = max_element(vec.begin(), vec.end());
    cout << "max elem: " << *pos << endl;

    //����
    sort(vec.begin(), vec.end());
    for(vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    //����Ԫ��
    pos = find(vec.begin(), vec.end(), 4);
    if(pos != vec.end())
        cout << "find: " << *pos << endl;

    //��ת
    reverse(pos, vec.end());
    for(vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    /*
    reverse(vec.begin(), vec.end());
    for(vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
    */
}

int main()
{
    //myAlgorithm();

    myRemove();

    return 0;
}
