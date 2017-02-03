#include <iostream>

using namespace std;

template<class T>
class SharePtr{
public:
    SharePtr(const T* _ptr)                     //Ĭ�Ϲ��캯��
    {
        ptr = const_cast<T*>(_ptr);
        count = 1;

        cout << "Ĭ�Ϲ��캯��" << endl;
    }

    template<class U>                           //����Ĭ�Ϲ��캯��
    SharePtr(const U* Ptr)
    {
        ptr = static_cast<T*>(Ptr);
        count = 1;

        cout << "����Ĭ�Ϲ��캯��" << endl;
    }

    SharePtr(const SharePtr<T>& Ptr)            //Ĭ�ϸ��ƹ��캯��
    {
        ptr = Ptr.ptr;
        ++count;

        cout << "Ĭ�ϸ��ƹ��캯��" << endl;
    }

    template<class U>                           //�������ƹ��캯��
    SharePtr(const SharePtr<U>& Ptr)
    {
        ptr = static_cast<T*>(Ptr.getPtr());
        ++count;

        cout << "�������ƹ��캯��" << endl;
    }

    SharePtr& operator=(const T* _ptr)
    {
        ptr = _ptr;
        ++count;

        cout << "����=�Ų�����" << endl;

        return *this;
    }

    template<class U>
    SharePtr& operator=(const SharePtr<U>& _ptr)
    {
        ptr = static_cast<T*>(_ptr.getPtr());
        ++count;

        cout << "��������=�Ų�����" << endl;

        return *this;
    }

    ~SharePtr()                                 //��������
    {
        if(0 == --count)
        {
            delete ptr;
            ptr = NULL;

            cout << "��������" << endl;
        }
    }

    T* getPtr() const
    {
        return ptr;
    }

private:
    T *ptr;
    static size_t count;
};

template<class T>
size_t SharePtr<T>::count = 0;

int main()
{
    SharePtr<int> T(new int);
    SharePtr<int> T1 = T;

    return 0;
}
