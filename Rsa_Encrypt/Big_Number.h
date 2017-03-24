/******************************************************************************
*    > File Name: Big_Number.h
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

//大数的储存
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
    //加法
    friend BigNumber operator+(const BigNumber &lhs, const BigNumber &rhs);

    //减法
    friend BigNumber operator-(const BigNumber &lhs, const BigNumber &rhs);

    //乘法
    friend BigNumber operator*(const BigNumber &lhs, const BigNumber &rhs);

    //除法
    friend BigNumber operator/(const BigNumber &lhs, const BigNumber &rhs);

private:
    string big_number_;     //用于保存大数
};


#endif // BIG_NUNBER_H
