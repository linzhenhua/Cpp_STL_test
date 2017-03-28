/******************************************************************************
*    > File Name: rsa_encrypt.h
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
#ifndef RSA_ENCRYPT_H
#define RSA_ENCRYPT_H

//RSA加解密
class RsaEncrypt{
public:
    typedef unsigned int uint;

    //默认构造函数
    RsaEncrypt(const uint &lhs, const uint &rhs);

    //复制构造函数
    RsaEncrypt(const RsaEncrypt &rhs);

    //重载=操作符
    RsaEncrypt& operator=(const RsaEncrypt &rhs);

    virtual ~RsaEncrypt();   //虚析构函数

public:
    uint get_prime1() const;
    uint get_prime2() const;
    uint get_product() const;
    uint get_aoLa() const;
    uint get_random_number() const;
    int get_modular_multiplicative_inverse() const;

    //产生RSA公、私密钥
    bool ProduceRsaKey();

    //加密
    uint Encrypt(uint m) const;

    //解密
    uint Decrypt(uint c) const;

private:
    //判断参数prime是否为素数(素数就是质数)
    bool JudgePrime(uint prime) const;

    //算出prime1_ * prime2_的欧拉值AoLa
    bool CountAolaNum();

    //求两个数的最大公因数
    uint CountCommonData(uint a, uint b) const;

    //随机选择一个数
    bool RandSelectRandomNumber();

    //求模反元素
    int ExtendedEuclidean(int n, int m, int &x, int &y) const;

private:
    //prime1_、prime2_：随机选择两个不相等的质数
    uint prime1_;
    uint prime2_;

    //product_：prime1_和prime2_的乘积product_
    uint product_;

    //aola_：欧拉函数值
    uint aola_;

    //random_number_：随机数
    uint random_number_;

    //modular_multiplicative_inverse_：模反元素
    int modular_multiplicative_inverse_;
};

#endif // RSA_ENCRYPT_H
