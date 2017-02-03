#include <iostream>

using namespace std;

template<typename T>
class Rational{
public:
    Rational(const T& num = 0, const T& den = 0):
        numerator(num), denominator(den){}

    ~Rational(){}

    Rational(const Rational<T>& rhs)
    {
        numerator = rhs.numerator;
        denominator = rhs.denominator;
    }

    Rational<T>& operator=(const Rational<T>& rhs)
    {
        numerator = rhs.numerator;
        denominator = rhs.denominator;

        return *this;
    }

    //template<typename T>   不可以加,会报错的
    friend Rational<T> operator*(const Rational<T>& lhs, const Rational<T>& rhs)
    {
        return Rational(lhs.retNum() * rhs.retNum(), lhs.retDen() * rhs.retDen());
    }

    const T retNum() const
    {
        return numerator;
    }

    const T retDen() const
    {
        return denominator;
    }

private:
    T numerator;
    T denominator;
};

int main()
{
    Rational<int> R(1,1);
    cout << R.retNum() << ' ' << R.retDen() << endl;

    Rational<int> R1 = R * 2;
    cout << R1.retNum() << ' ' << R1.retDen() << endl;

    Rational<int> R2 = 2 * R;
    cout << R2.retNum() << ' ' << R2.retDen() << endl;

    return 0;
}
