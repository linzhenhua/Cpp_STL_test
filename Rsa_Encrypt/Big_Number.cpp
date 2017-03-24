/******************************************************************************
*    > File Name: Big_Number.cpp
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
#include "Big_Number.h"

//默认构造函数
BigNumber::BigNumber(const string &rhs)
{
    big_number_ = rhs;
}

//复制构造函数
BigNumber::BigNumber(const BigNumber &rhs)
{
    big_number_ = rhs.big_number_;
}

//重载=操作符
BigNumber& BigNumber::operator=(const BigNumber &rhs)
{
    big_number_ = rhs.big_number_;

    return *this;
}

//析构函数
BigNumber::~BigNumber()
{}

//加法
BigNumber BigNumber::operator+(const BigNumber &lhs, const BigNumber &rhs)
{

}

//减法
BigNumber BigNumber::operator-(const BigNumber &lhs, const BigNumber &rhs)
{
}

//乘法
BigNumber BigNumber::operator*(const BigNumber &lhs, const BigNumber &rhs)
{
}

//除法
BigNumber BigNumber::operator/(const BigNumber &lhs, const BigNumber &rhs)
{
}
