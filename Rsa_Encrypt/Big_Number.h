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

//�����Ĵ���
class BigNumber{
public:
    //Ĭ�Ϲ��캯��
    BigNumber(const string &rhs);

    //���ƹ��캯��
    BigNumber(const BigNumber &rhs);

    //����=������
    BigNumber& operator=(const BigNumber &rhs);

    //��������
    virtual ~BigNumber();

public:
    //�ӷ�
    friend BigNumber operator+(const BigNumber &lhs, const BigNumber &rhs);

    //����
    friend BigNumber operator-(const BigNumber &lhs, const BigNumber &rhs);

    //�˷�
    friend BigNumber operator*(const BigNumber &lhs, const BigNumber &rhs);

    //����
    friend BigNumber operator/(const BigNumber &lhs, const BigNumber &rhs);

private:
    string big_number_;     //���ڱ������
};


#endif // BIG_NUNBER_H
