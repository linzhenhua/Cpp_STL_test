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

//Ĭ�Ϲ��캯��
BigNumber::BigNumber(const string &rhs)
{
    big_number_ = rhs;
}

//���ƹ��캯��
BigNumber::BigNumber(const BigNumber &rhs)
{
    big_number_ = rhs.big_number_;
}

//����=������
BigNumber& BigNumber::operator=(const BigNumber &rhs)
{
    big_number_ = rhs.big_number_;

    return *this;
}

//��������
BigNumber::~BigNumber()
{}

//�ӷ�
BigNumber BigNumber::operator+(const BigNumber &lhs, const BigNumber &rhs)
{

}

//����
BigNumber BigNumber::operator-(const BigNumber &lhs, const BigNumber &rhs)
{
}

//�˷�
BigNumber BigNumber::operator*(const BigNumber &lhs, const BigNumber &rhs)
{
}

//����
BigNumber BigNumber::operator/(const BigNumber &lhs, const BigNumber &rhs)
{
}
