#include <iostream>

using namespace std;

/**************************
����ڵ�
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
����
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
    //listNode<T> *node;     //�ڵ�
    listNode<T> *head;       //ͷָ��
    listNode<T> *tail;       //βָ��
    int length;              //������
};

template<typename T>
myList<T>::myList()
{
    head = new listNode<T>();
    tail = head;
    length = 0;
}

//����ԭ������βָ������ƶ�������Ԫ��
template<typename T>
void myList<T>::initList(const listNode<T>& node)
{
    listNode<T> *tmp = new listNode<T>(node.element, node.next);
    tail->next = tmp;
    tail = tmp;
    length++;      //ͷ�ڵ�Ϊλ��0
}

/*
//����ԭ������λ�ò���Ԫ��
template<typename T>
bool myList<T>::insertElem(const listNode<T>& node, const unsigned &pos)
{
    //List.insertElem(node2, 2);
    //�жϲ���λ��pos�Ƿ����
    if(pos <= 0 || pos > length)
    {
        cout << "����λ�ô���" << endl;
        return false;
    }

    //ͷ�ڵ�0������Ԫ��
    listNode<T> *p = head->next;

    //�ҳ�Ҫ�����λ��
    int i = 1;
    while(i <= pos || p != nullptr)
    {
        p = p->next;
        i++;
    }
    cout << "���ȣ�" << length << endl;
    //�������
    listNode<T>* tmp = new listNode<T>(node.element, node.next);
    cout << "���ȣ�" << length << endl;
    tmp->next = p->next;
    cout << "���ȣ�" << length << endl;
    p->next = tmp;
    ++length;

    return true;
}
*/
//ɾ������
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

    cout << "ɾ������ɹ�" << endl;
}

template<typename T>
void myList<T>::printElem() const
{
    listNode<T> *p = head->next;

    cout << "�����ȣ�" << length << endl;

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


//�ڴ�й¶����
//valgrind --leak-check=full ./a

//float x = (float)5;
