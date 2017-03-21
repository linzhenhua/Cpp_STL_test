/******************************************************************************
*    > File Name: key_produce.h
*
*    >Description:
*
*    >Version: 1.0
*    >Created Time: 20170316
*    >Revision: none
*    >Compiler: gcc
*
*    > Author: linzhenhua
*    > Mail: linzhenhualzh@163.com
*    > Company:
*
******************************************************************************/
#ifndef CKEY_PRODUCE_H
#define CKEY_PRODUCE_H

class RSA_Encrypt{
public:
    typedef unsigned int uint;

    //默认构造函数
    RSA_Encrypt(const uint &a, const uint &b);

    //复制构造函数
    RSA_Encrypt(const RSA_Encrypt &rhs);

    //重载=操作符
    RSA_Encrypt& operator=(const RSA_Encrypt &rhs);

    virtual ~RSA_Encrypt();   //虚析构函数

public:
    uint get_p() const;
    uint get_q() const;
    uint get_n() const;
    uint get_AoLa() const;
    uint get_e() const;
    int get_d() const;

    //产生RSA公、私密钥
    bool Produce_RSA_key();

    //加密
    uint encrypt(uint m);

    //解密
    uint decrypt(uint c);

private:
    //判断参数prime是否为素数(素数就是质数)
    bool JudgePrime(uint prime);

    //算出p*q的欧拉值AoLa
    bool CountAoLaNum();

    //求两个数的最大公因数
    uint CountCommonData(uint a, uint b);

    //随机选择公钥e
    bool RandSelectE();

    //求模反元素
    int ExtendedEuclidean(int n, int m, int &x, int &y);

private:
    //p、q：随机选择两个不相等的质数p和q
    uint p;
    uint q;

    //n：p和q的乘积n
    uint n;

    //AoLa：欧拉函数值
    uint AoLa;

    //e：随机数e
    uint e;

    //d：模反元素
    int d;
};

#endif // CKEY_PRODUCE_H
