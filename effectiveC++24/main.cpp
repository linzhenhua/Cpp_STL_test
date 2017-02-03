#include <iostream>

using namespace std;

//��������
class Rational{
public:
    //Ĭ�Ϲ��캯��
    Rational(double numerator = 0.0, double denominator = 0.0):
        m_iNumerator(numerator), m_iDenominator(denominator){}

    //��������
    ~Rational(){}

    //���ƹ��캯��
    Rational(const Rational &rhs);

    //����=������
    Rational& operator=(const Rational &rhs);

    //����+=������
    Rational& operator+=(const Rational &rhs);

    //����+����������������+=ʵ��
    Rational const operator+(const Rational &rhs) const;

    //����-������
    Rational const operator-(const Rational &rhs) const;

    //����*������
    Rational const operator*(const Rational &rhs) const;

    //����/������
    Rational const operator/(const Rational &rhs) const;

    //����==������
    bool const operator==(const Rational &rhs) const;

    //����!=������
    bool const operator!=(const Rational &rhs) const;

    void print();

    double getNumerator();

    double getDenominator();

private:
    double m_iNumerator;
    double m_iDenominator;
};


//�����������ʽ�����֣�����Ϊ��ĳ�Ա����������Ϊ�����Ԫ����

//����+=������
Rational& Rational::operator+=(const Rational &rhs)
{
    m_iNumerator += rhs.m_iNumerator;
    m_iDenominator += rhs.m_iDenominator;

    return *this;
}

//+=�޸��������ֵ���������+ʱ����+=��������
//����+����������������+=ʵ��
Rational const Rational::operator+(const Rational &rhs) const
{
    return Rational(m_iNumerator + rhs.m_iNumerator,
                    m_iDenominator + rhs.m_iDenominator);
}

//����-������
Rational const Rational::operator-(const Rational &rhs) const
{

    return Rational(m_iNumerator - rhs.m_iNumerator,
                    m_iDenominator - rhs.m_iDenominator);
}

//����*������
Rational const Rational::operator*(const Rational &rhs) const
{
    return Rational(m_iNumerator * rhs.m_iNumerator,
                    m_iDenominator * rhs.m_iDenominator);
}

//����/������
Rational const Rational::operator/(const Rational &rhs) const
{
    return Rational(m_iNumerator / rhs.m_iNumerator,
                    m_iDenominator / rhs.m_iDenominator);
}

//����==������
bool const Rational::operator==(const Rational &rhs) const
{
    if(m_iNumerator == rhs.m_iNumerator
            && m_iDenominator == rhs.m_iDenominator)
            return true;
    else
        return false;
}

//����!=������
bool const Rational::operator!=(const Rational &rhs) const
{
    return !(*this == rhs);
}

//���ظ��ƹ��캯��
Rational::Rational(const Rational &rhs)
{
    m_iNumerator = rhs.m_iNumerator;
    m_iDenominator = rhs.m_iDenominator;
}

//����=������
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
    //R1.operator+(1);�൱��
    //Rational temp(1);
    //R4 = R1 + temp;

    //cout << R4.getNumerator() << endl;
    //cout << R4.getDenominator() << endl;

    R4.print();
    //1 + R1;       //����

    return 0;
}
