/******************************************************************************
*    > File Name: key_encrypt.cpp
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
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "rsa_encrypt.h"

using namespace std;

//默认构造函数
//  prime1_、prime2：随机选择两个不相等的质数
//  product_：prime1_和prime2_的乘积
//  aola：欧拉函数值
//  random_number_：随机数
//  modular_multiplicative_inverse_：模反元素
RsaEncrypt::RsaEncrypt(const uint &lhs, const uint &rhs)
{
    prime1_ = lhs;
    prime2_ = rhs;
    product_ = 0;
    aola_ = 0;
    random_number_ = 0;
    modular_multiplicative_inverse_ = 0;
}

//复制构造函数
RsaEncrypt::RsaEncrypt(const RsaEncrypt &rhs)
{
    prime1_ = rhs.prime1_;
    prime2_ = rhs.prime2_;
    product_ = rhs.product_;
    aola_ = rhs.aola_;
    random_number_ = rhs.random_number_;
    modular_multiplicative_inverse_ = rhs.modular_multiplicative_inverse_;
}

//重载=操作符
RsaEncrypt& RsaEncrypt::operator=(const RsaEncrypt &rhs)
{
    prime1_ = rhs.prime1_;
    prime2_ = rhs.prime2_;
    product_ = rhs.product_;
    aola_ = rhs.aola_;
    random_number_ = rhs.random_number_;
    modular_multiplicative_inverse_ = rhs.modular_multiplicative_inverse_;

    return *this;
}

//虚析构函数
RsaEncrypt::~RsaEncrypt()
{}

RsaEncrypt::uint RsaEncrypt::get_prime1() const
{
    return prime1_;
}

RsaEncrypt::uint RsaEncrypt::get_prime2() const
{
    return prime2_;
}

RsaEncrypt::uint RsaEncrypt::get_product() const
{
    return product_;
}

RsaEncrypt::uint RsaEncrypt::get_aoLa() const
{
    return aola_;
}

RsaEncrypt::uint RsaEncrypt::get_random_number() const
{
    return random_number_;
}

int RsaEncrypt::get_modular_multiplicative_inverse() const
{
    return modular_multiplicative_inverse_;
}

//判断参数prime是否为素数(素数就是质数)
//质数：质数定义为在大于1的自然数中，除了1和它本身以外不再有其他因数的数称为质数
//参数：一个正整数，判断是否为素数
//返回值：
//   false：不是素数
//   true：是素数
bool RsaEncrypt::JudgePrime(uint prime) const
{
    if(prime == 0)
        return false;

    uint i;

    uint limit = (uint)sqrt( (double)prime );  //开根号

    for(i = 2; i <= limit; ++i)
    {
        if(prime % i == 0)
        {
            return false;
        }
    }

    return true;
}

//算出prime1_ * prime2_的欧拉值φ(n) = (prime1_-1)(prime2_-1)
//参数：prime1_、prime2_为素数
//      aola_：欧拉函数的值
//返回值：
//      false：prime1_或者prime2_不为素数
//      true：求出了欧拉值，通过指针参数aola_返回
bool RsaEncrypt::CountAolaNum()
{
    if( !JudgePrime(prime1_) )
    {
        return false;
    }

    if( !JudgePrime(prime2_) )
    {
        return false;
    }
    //求欧拉函数的值
    aola_ = (prime1_ - 1)*(prime2_ - 1);

    return true;
}

//求两个数的最大公因数(辗转相除法)
//eg:a=25,b=15，a/b=1......10,b/10=1......5,10/5=2.......0,
//最后一个为被除数余数的除数就是5, 5就是所求最大公约数
//random_number_与φ(n)互质,所以最大公因数为1
RsaEncrypt::uint RsaEncrypt::CountCommonData(uint a, uint b) const
{
    uint c;

    c = a%b;

    if( c )
    {
        return CountCommonData(b, c);
    }
    else
    {
        return b;
    }
}

//随机选择公钥random_number_
//随机选择一个整数random_number_，条件是1< random_number_ < φ(n) (2 <= random_number_ < φ(n))，
//且random_number_与φ(n)互质；(φ(n)为欧拉函数值)
//（实际应用中，random_number_常常选择65537）
//返回值：
//      false：求随机数失败
//      true：求出了随机数，通过指针参数random_number_返回
//思考是否会栈溢出
bool RsaEncrypt::RandSelectRandomNumber()
{
    //为什么欧拉函数值aoLa_ <= 2，因为1< random_number_ < φ(n)，如果取值<=2的话，
    //整数random_number_就没有值可以取了
    if(aola_ <= 2)
    {
        return false;
    }

    //初始化随机数发生器
    srand(time(0));

    uint tmp;   //用来临时保存欧拉函数值φ(n)
    do
    {
        //1< random_number_ < φ(n)相当于(2 <= random_number_ < φ(n))  random_number_为整数
        //要取得[a,b)的随机整数，使用(rand() % (b-a))+ a
        tmp = ((uint)rand() % (aola_ - 2)) + 2;

    //CountCommonData(tmp, aola_)是为了tmp与aola_互质(两个质数的最大公因数是1)
    }while( CountCommonData(tmp, aola_) != 1 );

    random_number_ = tmp;

    //测试
    //random_number_ = 17;

    return true;
}

//求模反元素
//拓展的欧几里得算法:
//n,m互质
//对于不完全为 0 的非负整数 n，m，gcd（n，m）表示 n，m的最大公约数，
//必然存在整数对 x，y ，使得 gcd（n，m）=ax+by。
//n * x + m * y = 1
int RsaEncrypt::ExtendedEuclidean(int n, int m, int &x, int &y) const
{
    if (m == 0)
    {
        x = 1;
        y = 0;
        return n;
    }
    //cout << n << "|" << m << endl;

    int ans = ExtendedEuclidean(m, n % m, x, y);

    int temp = x;
    x = y;
    y = temp - n / m * y;

    return ans;
}

//产生RSA公、私密钥
//参数：
//      prime1_、prime2_：随机选择两个不相等的质数
//      product_：prime1_和prime1_的乘积product_
//      random_number_：随机数random_number_
//      modular_multiplicative_inverse_：模反元素
//返回值：
//      true:  生成密钥成功
//      false: 失败
bool RsaEncrypt::ProduceRsaKey()
{
    product_ = prime1_ * prime2_;

    int x, y;      //模反元素

    if( CountAolaNum() )     //算出p*q的欧拉值φ(n) = (p-1)(q-1)
    {
        if( RandSelectRandomNumber() )     //算出随机数random_number_
        {
            //n * x + m * y = 1
            ExtendedEuclidean(random_number_, aola_, x, y); //算出模反元素

            //如果x为负，一般把它“正过来”，即再加上AoLa值
            if(x < 0)
            {
                x += aola_;
            }
            modular_multiplicative_inverse_ = x;

            //测试
            //modular_multiplicative_inverse_ = 2753;

            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

//加密
//公式：me ≡ c (mod n)
//m的e次方除以n的余数为c
//参数m：待加密的信息
//返回值：加密后的信息
RsaEncrypt::uint RsaEncrypt::Encrypt(uint m) const
{
    uint EncryptInfo = 1;   //加密后的信息

    uint i;
    for( i=0; i < random_number_; ++i)       //=========用了乘的模 等于 模的乘
    {
        EncryptInfo *= m;
        if( EncryptInfo >= product_ )
        {
            EncryptInfo %= product_;
        }
        if(!EncryptInfo)
            return EncryptInfo;
    }
    return EncryptInfo%product_;
}

//解密
//公式：cd ≡ m (mod n)
//c的d次方除以n的余数为m
//参数c：待解密的信息
//返回值：解密后的信息
RsaEncrypt::uint RsaEncrypt::Decrypt(uint c) const
{
    uint EncryptInfo = 1;   //解密后的信息

    int i;

    //cout << c << "|" << d << "|" <<  n << endl;
    for( i=0; i < modular_multiplicative_inverse_; ++i)       //=========用了乘的模 等于 模的乘
    {
        EncryptInfo *= c;
        if( EncryptInfo >= product_ )
        {
            EncryptInfo %= product_;
        }
        if(!EncryptInfo)
            return EncryptInfo;
    }
    return EncryptInfo%product_;
}
