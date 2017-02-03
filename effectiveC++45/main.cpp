#include <iostream>

using namespace std;

template<class T>
class SharePtr{
public:
    SharePtr(const T* _ptr)                     //默认构造函数
    {
        ptr = const_cast<T*>(_ptr);
        count = 1;

        cout << "默认构造函数" << endl;
    }

    template<class U>                           //泛化默认构造函数
    SharePtr(const U* Ptr)
    {
        ptr = static_cast<T*>(Ptr);
        count = 1;

        cout << "泛化默认构造函数" << endl;
    }

    SharePtr(const SharePtr<T>& Ptr)            //默认复制构造函数
    {
        ptr = Ptr.ptr;
        ++count;

        cout << "默认复制构造函数" << endl;
    }

    template<class U>                           //泛化复制构造函数
    SharePtr(const SharePtr<U>& Ptr)
    {
        ptr = static_cast<T*>(Ptr.getPtr());
        ++count;

        cout << "泛化复制构造函数" << endl;
    }

    SharePtr& operator=(const T* _ptr)
    {
        ptr = _ptr;
        ++count;

        cout << "重载=号操作符" << endl;

        return *this;
    }

    template<class U>
    SharePtr& operator=(const SharePtr<U>& _ptr)
    {
        ptr = static_cast<T*>(_ptr.getPtr());
        ++count;

        cout << "泛化重载=号操作符" << endl;

        return *this;
    }

    ~SharePtr()                                 //析构函数
    {
        if(0 == --count)
        {
            delete ptr;
            ptr = NULL;

            cout << "析构函数" << endl;
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
