#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <string>

using namespace std;

int Mul2(int &x)
{
    return x = x*2;
}

bool IsOdd(int x)
{
    return x%2 != 0;
}

void Print(int x)
{
    cout << x << " ";
}

bool myfn(int i, int j)
{
    return abs(i) < abs(j);
}

void myAlgorithm()
{
    vector<int> vec;

    //插入元素
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(9);
    vec.push_back(8);

    //遍历
    for(vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vector<int>::iterator pos;

    //最小值
    pos = min_element(vec.begin(), vec.end());
    cout << "min elem: " << *pos << endl;

    //最大值
    pos = max_element(vec.begin(), vec.end());
    cout << "max elem: " << *pos << endl;

    //排序
    sort(vec.begin(), vec.end());
    for(vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    //查找元素
    pos = find(vec.begin(), vec.end(), 4);
    if(pos != vec.end())
        cout << "find: " << *pos << endl;

    //反转
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

void myRemove()
{
    int arr[] = {0,1,2,3,4,8,6,7,8,9};
    vector<int> myVec(arr, arr+sizeof(arr)/sizeof(int));

    for(vector<int>::const_iterator iter = myVec.begin(); iter != myVec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vector<int>::iterator removeIter;
    removeIter = remove(myVec.begin(), myVec.end(), 8);
    //remove(myVec.begin(), myVec.end(), 7);
    //remove(myVec.begin(), myVec.end(), 1);

    myVec.erase(removeIter, myVec.end());     //物理删除
    for(vector<int>::const_iterator iter = myVec.begin(); iter != myVec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vector<int>::iterator findIter;
    findIter = find(myVec.begin(), myVec.end(), 9);
    if(findIter != myVec.end())
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

    vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));
    vector<int>::iterator iter;
    iter = remove_if(vec.begin(), vec.end(), IsOdd);   //如果是奇数(使得IsOdd函数成立)的话就移除
    vec.erase(iter, vec.end());
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vec.assign(arr, arr+sizeof(arr)/sizeof(int));
    vector<int> vec1(11);
    iter = remove_copy_if(vec.begin(), vec.end(), vec1.begin(), IsOdd);
    vec1.erase(iter, vec1.end());
    copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void ForEach()
{
    vector<int> vec;

    for(int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for_each(vec.begin(), vec.end(), Mul2);

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
/*
    for_each( vec.begin(), vec.end(), not1( ptr_fun(IsOdd) ) );

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for_each(vec.begin(), vec.end(), Print);
*/
}

void Count()
{
    vector<int> vec;

    for(int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //int my_count = count(vec.begin(), vec.end(), 1);

    int my_count = count_if(vec.begin(), vec.end(), IsOdd);

    cout << my_count << endl;
}

void MinElement()
{
    vector<int> vec;

    for(int i = 1; i < 10; ++i)
    {
        vec.push_back(-i);
    }
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int>::iterator my_min_element = min_element(vec.begin(), vec.end());

    cout << *my_min_element << endl;

    vector<int>::iterator my_max_element = max_element(vec.begin(), vec.end());

    cout << *my_max_element << endl;

    vector<int>::iterator my_element = max_element(vec.begin(), vec.end(), myfn);

    cout << *my_element << endl;
}

void Find()
{
    vector<int> vec;

    for(int i = 2; i < 10; ++i)
    {
        vec.push_back(i);
    }
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
/*
    //find()函数记得判断返回值
    vector<int>::iterator iter = find(vec.begin(), vec.end(), 10);
    if(iter == vec.end())
        return ;
    cout << *iter << endl;
*/
    vector<int>::iterator iter1 = find_if(vec.begin(), vec.end(), IsOdd);
    if(iter1 == vec.end())
        return ;
    cout << *iter1 << endl;

}

void Search()
{
    vector<int> vec;

    for(int i = 2; i < 10; ++i)
    {
        vec.push_back(i);
    }
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    int arr[] = {5,6,7,8};

    vector<int>::iterator iter = search(vec.begin(), vec.end(), arr, arr+4);
    if(iter != vec.end())
    {
        cout << iter - vec.begin() << endl;
        cout << *iter << endl;
    }

    iter = search_n(vec.begin(), vec.end(), 4, 3, greater<int>());
    if(iter != vec.end())
    {
        cout << iter - vec.begin() << endl;
        cout << *iter << endl;
    }
}

void FindEnd()
{
    int arr1[] = {0,1,2,3,4,5,0,1,7,8,9};
    vector<int> vec(arr1, arr1+10);

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    int arr2[] = {0,1};
    vector<int>::iterator iter = find_end(vec.begin(), vec.end(), arr2, arr2+2);
    if(iter != vec.end())
        cout << iter - vec.begin() << endl;
}

void FindFirstOf()
{
    int arr1[] = {0,10,2,3,4,5,0,1,7,8,9};
    vector<int> vec(arr1, arr1+11);

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    int arr2[] = {0,10,2};

    vector<int>::iterator iter = find_first_of(vec.begin(), vec.end(), arr2, arr2+3);
    if(iter != vec.end())
        cout << iter - vec.begin() << endl;
}

void AdjacentFind()
{
    int arr1[] = {0,10,2,3,3,5,0,1,7,8,9};
    vector<int> vec(arr1, arr1 + sizeof(arr1)/sizeof(int));

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int>::iterator iter = adjacent_find(vec.begin(), vec.end());
    if(iter != vec.end())
        cout << iter - vec.begin() << endl;
}

void Equal()
{
    int arr1[] = {0,10,2,3,3,5,0,1,7,8,9};
    vector<int> vec(arr1, arr1 + sizeof(arr1)/sizeof(int));

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    bool flag = equal(vec.begin(), vec.end(), arr1);
    if(flag)
    {
        cout << "vec have arr2" << endl;
    }
    else
    {
        cout << "vec no have arr2" << endl;
    }
}

bool mypredicate(int i, int j)
{
  return (i==j);
}

void Mismatch()
{
    int arr1[] = {0,10,2,3,3,5,0,1,7,8,9};
    vector<int> vec( arr1, arr1 + sizeof(arr1)/sizeof(int) );

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    int arr2[] = {0,10,3,3,3,5,0,1,7,9,9};

    copy(arr2, arr2+sizeof(arr2)/sizeof(int), ostream_iterator<int>(cout, " "));
    cout << endl;

    pair<vector<int>::iterator, int*> my_pair;

    my_pair = mismatch(vec.begin(), vec.end(), arr2);
    if(my_pair.first != vec.end())
        cout << *my_pair.first << " " << *my_pair.second << endl;

    my_pair.first++;
    my_pair.second++;

    my_pair = mismatch(my_pair.first, vec.end(), my_pair.second, mypredicate);
    if(my_pair.first != vec.end())
        cout << *my_pair.first << " " << *my_pair.second << endl;
}

void Copy()
{
    int arr1[] = {0,1,2,3,3,5,0,1,7,8,9};
    vector<int> vec( arr1, arr1 + sizeof(arr1)/sizeof(int) );

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> vec1;

    copy(vec.begin(), vec.end(), back_inserter(vec1));
    copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> vec2(10);
    copy_backward(vec.begin(), vec.end(), vec2.end());
    copy(vec2.begin(), vec2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> vec3;
    vec3.assign(vec1.begin(), vec1.end());
    copy(vec3.begin(), vec3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //copy(istream_iterator<string>(cin),istream_iterator<string>(),
    //     ostream_iterator<string>(cout, "\n") );

    vector<int> vec4(11);
    copy(vec3.rbegin(), vec3.rend(), vec4.begin());
    copy(vec4.begin(), vec4.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void Transform()
{
    int arr1[] = {0,1,2,3,3,5,0,1,7,8,9};
    vector<int> vec( arr1, arr1 + sizeof(arr1)/sizeof(int) );

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> vec1;

    transform(vec.begin(), vec.end(), back_inserter(vec1), bind2nd(plus<int>(), 2));

    copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
}

void Replace()
{
    int arr1[] = {0,1,2,3,4,5,6,7,8,9,10};
    vector<int> vec( arr1, arr1 + sizeof(arr1)/sizeof(int) );

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    replace(vec.begin(), vec.end(), 3, 10);

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    replace_if(vec.begin(), vec.end(), IsOdd, 22);

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> vec1;
    replace_copy(vec.begin(), vec.end(), back_inserter(vec1), 2, 11);

    copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> vec2;
    replace_copy_if(vec1.begin(), vec1.end(), back_inserter(vec2), IsOdd, 12);

    copy(vec2.begin(), vec2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void Unique()
{
    int arr1[] = {0,1,1,2,3,4,5,5,5,6,7,8,9,10};
    vector<int> vec( arr1, arr1 + sizeof(arr1)/sizeof(int) );

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int>::iterator iter = unique(vec.begin(), vec.end());
    vec.erase(iter, vec.end());
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> vec1;
    vec.assign(arr1, arr1 + sizeof(arr1)/sizeof(int));
    unique_copy(vec.begin(), vec.end(), back_inserter(vec1));
    copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void Reverse()
{
    int arr1[] = {0,1,2,3,4,5,6,7,8,9,10};
    vector<int> vec( arr1, arr1 + sizeof(arr1)/sizeof(int) );

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    reverse(vec.begin(), vec.end());
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> vec1;
    reverse_copy(vec.begin(), vec.end(), back_inserter(vec1));
    copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void Rotate()
{
    int arr1[] = {0,1,2,3,4,5,6,7,8,9,10};
    vector<int> vec( arr1, arr1 + sizeof(arr1)/sizeof(int) );

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    rotate(vec.begin(), vec.begin()+1, vec.end());

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> vec1;
    rotate_copy(vec.begin(), vec.begin()+1, vec.end(), back_inserter(vec1));

    copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void Permutation()
{
    int arr[] = {1,2,3};

    sort(arr, arr+sizeof(arr)/sizeof(int));

    while(next_permutation(arr, arr+3))
    {
        cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
    }
    cout << "after loop:" << endl;
    cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
    cout << endl;

    int arr1[] = {3,2,1};
    sort(arr1, arr1+sizeof(arr1)/sizeof(int));
    reverse(arr1, arr1+sizeof(arr1)/sizeof(int));

    while(prev_permutation(arr1, arr1+3))
    {
        cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[2] << endl;
    }
    cout << "after loop:" << endl;
    cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[2] << endl;

    int arr2[] = {1,2,3,4,5};
    sort(arr2, arr2+sizeof(arr2)/sizeof(int));

    int x = 1;   //要包含原来的1,2,3,4,5这个次序，所以x是1
    while(next_permutation(arr2, arr2+5))
    {
        x++;
    }
    cout << x << endl;
}

int MyRandom(int i)
{
    return rand()%i;
}

void RandomShuffle()
{
    int arr1[] = {0,1,2,3,4,5,6,7,8,9,10};
    vector<int> vec( arr1, arr1 + sizeof(arr1)/sizeof(int) );

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    random_shuffle(vec.begin(), vec.end());

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    srand((unsigned int)time(0));     //初始化随机数生成器

    vector<int> vec1( arr1, arr1 + sizeof(arr1)/sizeof(int) );

    random_shuffle(vec1.begin(), vec1.end(), MyRandom);
    copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void Partition()
{
    int arr1[] = {0,1,2,3,4,5,6,7,8,9,10};
    vector<int> vec( arr1, arr1 + sizeof(arr1)/sizeof(int) );

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    partition(vec.begin(), vec.end(), IsOdd);

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    sort(vec.begin(), vec.end());

    stable_partition(vec.begin(), vec.end(), IsOdd);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void Sort()
{
    srand((unsigned int)time(0));     //初始化随机数生成器

    int arr1[] = {9,8,7,6,5,4,3,2,1};

    vector<int> vec( arr1, arr1 + sizeof(arr1)/sizeof(int) );
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    random_shuffle(vec.begin(), vec.end(), MyRandom);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    stable_sort(vec.begin(), vec.end());
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    random_shuffle(vec.begin(), vec.end(), MyRandom);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    partial_sort(vec.begin(), vec.begin()+4, vec.end());

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    random_shuffle(vec.begin(), vec.end(), MyRandom);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> vec1(15);
    vector<int>::iterator iter = partial_sort_copy(vec.begin(), vec.end(), vec1.begin(), vec1.end());
    copy(vec1.begin(), iter, ostream_iterator<int>(cout, " "));
    cout << endl;
}

bool myfunction (int i, int j)
{
    return (i>j);
}

void NthElement()
{
    srand((unsigned int)time(0));     //初始化随机数生成器

    int arr1[] = {9,8,7,6,5,4,3,2,1};

    vector<int> vec( arr1, arr1 + sizeof(arr1)/sizeof(int) );
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    random_shuffle(vec.begin(), vec.end(), MyRandom);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    nth_element(vec.begin(), vec.begin()+3, vec.end());

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    random_shuffle(vec.begin(), vec.end(), MyRandom);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    nth_element(vec.begin(), vec.begin()+3, vec.end(), myfunction);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void Heap()
{
    int arr1[] = {9,8,7,6,5,4,3,2,1};

    vector<int> vec(arr1, arr1 + sizeof(arr1)/sizeof(int) );
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    make_heap(vec.begin(), vec.end());
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vec.push_back(100);
    push_heap(vec.begin(), vec.end());
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    pop_heap(vec.begin(), vec.end());
    vec.pop_back();
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    sort_heap(vec.begin(), vec.end());
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    //myAlgorithm();

    //myRemove();

    //ForEach();

    //Count();

    //MinElement();

    //Find();

    //Search();

    //FindEnd();

    //FindFirstOf();

    //AdjacentFind();

    //Equal();

    //Mismatch();

    //Copy();

    //Transform();

    //Replace();

    //Unique();

    //Reverse();

    //Rotate();

    //Permutation();

    //RandomShuffle();

    //Partition();

    //Sort();

    //NthElement();

    Heap();

    return 0;
}
