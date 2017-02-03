#include <iostream>

using namespace std;

/**************************
链表节点
**************************/
template<typename T>
class listNode{
public:
    T element;
    listNode<T>* next;

    listNode(T elem = 0, listNode<T>* _next = nullptr):element(elem), next(_next){}
    ~listNode(){}
};

/**************************
链表
**************************/
template<typename T>
class myList{
public:
    //nullptr is C++11
    myList();
    ~myList(){}

    void initList(const listNode<T>& node);
    //bool insertElem(const listNode<T>& node, const unsigned &pos);
    //bool deleteElem(listNode<T> *x);
    void printElem() const;
    void delList();
    //listNode<T> searchElem(const unsigned &pos);

private:
    //listNode<T> *node;     //节点
    listNode<T> *head;       //头指针
    listNode<T> *tail;       //尾指针
    int length;              //链表长度
};

template<typename T>
myList<T>::myList()
{
    head = new listNode<T>();
    tail = head;
    length = 0;
}

//工作原理：就是尾指针向后移动来加入元素
template<typename T>
void myList<T>::initList(const listNode<T>& node)
{
    listNode<T> *tmp = new listNode<T>(node.element, node.next);
    tail->next = tmp;
    tail = tmp;
    length++;      //头节点为位置0
}

/*
//工作原理：任意位置插入元素
template<typename T>
bool myList<T>::insertElem(const listNode<T>& node, const unsigned &pos)
{
    //List.insertElem(node2, 2);
    //判断插入位置pos是否合理
    if(pos <= 0 || pos > length)
    {
        cout << "插入位置错误" << endl;
        return false;
    }

    //头节点0不插入元素
    listNode<T> *p = head->next;

    //找出要插入的位置
    int i = 1;
    while(i <= pos || p != nullptr)
    {
        p = p->next;
        i++;
    }
    cout << "长度：" << length << endl;
    //插入操作
    listNode<T>* tmp = new listNode<T>(node.element, node.next);
    cout << "长度：" << length << endl;
    tmp->next = p->next;
    cout << "长度：" << length << endl;
    p->next = tmp;
    ++length;

    return true;
}
*/
//删除链表
template<typename T>
void myList<T>::delList()
{
    listNode<T> *p, *tmp;

    p = head->next;
    head->next = nullptr;

    while(p != nullptr)
    {
        tmp = p->next;
        delete p;
        p = tmp;
    }
    length = 0;

    cout << "删除链表成功" << endl;
}

template<typename T>
void myList<T>::printElem() const
{
    listNode<T> *p = head->next;

    cout << "链表长度：" << length << endl;

    while(p != nullptr)
    {
        cout << p->element << endl;
        p = p->next;
    }
}

int main(int argc, char** argv)
{
    myList<int> List;

    //vector<int> vec;

    listNode<int> node(10,nullptr);
    List.initList(node);
    List.initList(node);
    List.initList(node);
    List.initList(node);
    List.initList(node);
    List.initList(node);

    List.printElem();
/*
    listNode<int> node1(1,nullptr);
    List.insertElem(node1, 1);

    listNode<int> node2(2);
    List.insertElem(node2, 2);

    listNode<int> node3(3);
    List.insertElem(node3, 3);

    listNode<int> node4(4);
    List.insertElem(node4, 4);

    List.printElem();
*/
    List.delList();

    return 0;
}


//内存泄露工具
//valgrind --leak-check=full ./a

//float x = (float)5;
