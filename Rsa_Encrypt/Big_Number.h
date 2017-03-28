/******************************************************************************
*    > File Name: big_number.h
*
*    >Description:
*
*    >Version: 1.0
*    >Created Time: 20170324
*    >Revision: none
*    >Compiler: gcc
*
*    > Author: linzhenhua
*    > Mail: linzhenhualzh@163.com
*    > Company:
*
******************************************************************************/
#ifndef BIG_NUNBER_H
#define BIG_NUNBER_H

#include <string>

using namespace std;

//大数的储存计算
class BigNumber{
public:
    //默认构造函数
    BigNumber(const string &rhs);

    //复制构造函数
    BigNumber(const BigNumber &rhs);

    //重载=操作符
    BigNumber& operator=(const BigNumber &rhs);

    //析构函数
    virtual ~BigNumber();

public:
    //加法（如果是成员函数，而不是友元函数，函数的参数只需一个，因为有一个默认的this指针）
    friend BigNumber operator+(const BigNumber &lhs, const BigNumber &rhs);

    //减法
    friend BigNumber operator-(const BigNumber &lhs, const BigNumber &rhs);

    //乘法
    friend BigNumber operator*(const BigNumber &lhs, const BigNumber &rhs);

    //除法
    friend BigNumber operator/(const BigNumber &lhs, const BigNumber &rhs);

    void print() const
    {
        cout << big_number_ << endl;
    }
private:
    string big_number_;                //用于保存大数
    static const int k_max_ = 1000;    //可以计算1000位的大数
};

#endif // BIG_NUNBER_H
