#include <iostream>

using namespace std;

class Student{
public:
    Student(float score = 0.0):m_iScore(score){}

    ~Student(){}

    Student(const Student& rhs);

    Student& operator=(const Student& rhs);

    void print();

private:
    float m_iScore;
};

Student::Student(const Student& rhs)
{
    m_iScore = rhs.m_iScore;
}

Student& Student::operator=(const Student& rhs)
{
    m_iScore = rhs.m_iScore;

    return *this;
}

void Student::print()
{
    cout << m_iScore << endl;
}

//��ģ��
template<typename T1, typename T2>
class Test{
public:
    Test(T1 t1, T2 t2):a(t1), b(t2)
    {
        cout << "��ģ��" << endl;
    }

    ~Test(){}

private:
    T1 a;
    T2 b;
};

//ģ��ȫ�ػ�
template<>
class Test<int, float>{
public:
    Test(int t1, float t2):a(t1), b(t2)
    {
        cout << "ģ��ȫ�ػ�" << endl;
    }

    ~Test(){}

private:
    int a;
    float b;
};

//ģ��ƫ�ػ�
template<typename T1>
class Test<T1, int>{
public:
    Test(T1 t1, int t2):a(t1), b(t2)
    {
        cout << "ģ��ƫ�ػ�" << endl;
    }

    ~Test(){}

private:
    T1 a;
    int b;
};

int main()
{
    Student S(100.00);
    S.print();

    Test<int, float> t1(1, 1.0);         //ȫ�ػ�
    Test<bool, int> t2(false, 2);         //ƫ�ػ�
    Test<float, float> t3(1.0, 2.0);     //ģ��

    return 0;
}
