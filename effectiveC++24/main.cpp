#include <iostream>

using namespace std;

//有理数类
class Rational{
public:
    //默认构造函数
    Rational(double numerator = 0.0, double denominator = 0.0):
        m_iNumerator(numerator), m_iDenominator(denominator){}

    //析构函数
    ~Rational(){}

    //复制构造函数
    Rational(const Rational &rhs);

    //重载=操作符
    Rational& operator=(const Rational &rhs);

    //重载+=操作符
    Rational& operator+=(const Rational &rhs);

    //重载+操作符，可以利用+=实现
    Rational const operator+(const Rational &rhs) const;

    //重载-操作符
    Rational const operator-(const Rational &rhs) const;

    //重载*操作符
    Rational const operator*(const Rational &rhs) const;

    //重载/操作符
    Rational const operator/(const Rational &rhs) const;

    //重载==操作符
    bool const operator==(const Rational &rhs) const;

    //重载!=操作符
    bool const operator!=(const Rational &rhs) const;

    void print();

    double getNumerator();

    double getDenominator();

private:
    double m_iNumerator;
    double m_iDenominator;
};


//运算符重载形式有两种，重载为类的成员函数和重载为类的友元函数

//重载+=操作符
Rational& Rational::operator+=(const Rational &rhs)
{
    m_iNumerator += rhs.m_iNumerator;
    m_iDenominator += rhs.m_iDenominator;

    return *this;
}

//+=修改了自身的值，如果重载+时调用+=会出问题的
//重载+操作符，可以利用+=实现
Rational const Rational::operator+(const Rational &rhs) const
{
    return Rational(m_iNumerator + rhs.m_iNumerator,
                    m_iDenominator + rhs.m_iDenominator);
}

//重载-操作符
Rational const Rational::operator-(const Rational &rhs) const
{

    return Rational(m_iNumerator - rhs.m_iNumerator,
                    m_iDenominator - rhs.m_iDenominator);
}

//重载*操作符
Rational const Rational::operator*(const Rational &rhs) const
{
    return Rational(m_iNumerator * rhs.m_iNumerator,
                    m_iDenominator * rhs.m_iDenominator);
}

//重载/操作符
Rational const Rational::operator/(const Rational &rhs) const
{
    return Rational(m_iNumerator / rhs.m_iNumerator,
                    m_iDenominator / rhs.m_iDenominator);
}

//重载==操作符
bool const Rational::operator==(const Rational &rhs) const
{
    if(m_iNumerator == rhs.m_iNumerator
            && m_iDenominator == rhs.m_iDenominator)
            return true;
    else
        return false;
}

//重载!=操作符
bool const Rational::operator!=(const Rational &rhs) const
{
    return !(*this == rhs);
}

//重载复制构造函数
Rational::Rational(const Rational &rhs)
{
    m_iNumerator = rhs.m_iNumerator;
    m_iDenominator = rhs.m_iDenominator;
}

//重载=操作符
Rational& Rational::operator=(const Rational &rhs)
{
    m_iNumerator = rhs.m_iNumerator;
    m_iDenominator = rhs.m_iDenominator;

    return *this;
}

void Rational::print()
{
    if(m_iDenominator < 0.0)
        cout << m_iNumerator << m_iDenominator << "i" << endl;
    else
        cout << m_iNumerator << "+" << m_iDenominator << "i" << endl;
}

double Rational::getNumerator()
{
    return m_iNumerator;
}

double Rational::getDenominator()
{
    return m_iDenominator;
}

int main(int argc, char **argv)
{
    Rational R1(4.0, 2.0);
    Rational R2(2.0, 1.0);
    Rational R3;

    cout << "R1(4.0, 2.0)" << endl << "R2(2.0, 1.0)" << endl;

    R3 = R1 + R2;
    cout << "(R1 + R2) = ";
    R3.print();

    R3 = R1 - R2;
    cout << "(R1 - R2) = ";
    R3.print();

    R3 = R1 * R2;
    cout << "(R1 * R2) = ";
    R3.print();

    R3 = R1 / R2;
    cout << "(R1 / R2) = ";
    R3.print();

    if(R1 == R2)
        cout << "R1 == R2" << endl;
    else
        cout << "R1 != R2" << endl;

    Rational R4;
    Rational R5(1,2);

    //cout << R4.getNumerator() << endl;
    //cout << R4.getDenominator() << endl;

    Rational R6;
    R4 = R6 + 1 + R5;
    //R1.operator+(1);相当于
    //Rational temp(1);
    //R4 = R1 + temp;

    //cout << R4.getNumerator() << endl;
    //cout << R4.getDenominator() << endl;

    R4.print();
    //1 + R1;       //错误

    return 0;
}
