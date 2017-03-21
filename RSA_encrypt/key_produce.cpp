/******************************************************************************
*    > File Name: key_produce.cpp
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
#include "key_produce.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

//默认构造函数
//  p、q：随机选择两个不相等的质数p和q
//  n：p和q的乘积n
//  AoLa：欧拉函数值
//  e：随机数e
//  d：模反元素
RSA_Encrypt::RSA_Encrypt(const uint &a, const uint &b)
{
    p = a;
    q = b;
    n = 0;
    AoLa = 0;
    e = 0;
    d = 0;
}

//复制构造函数
RSA_Encrypt::RSA_Encrypt(const RSA_Encrypt &rhs)
{
    p = rhs.p;
    q = rhs.q;
    n = rhs.n;
    AoLa = rhs.AoLa;
    e = rhs.e;
    d = rhs.d;
}

//重载=操作符
RSA_Encrypt& RSA_Encrypt::operator=(const RSA_Encrypt &rhs)
{
    p = rhs.p;
    q = rhs.q;
    n = rhs.n;
    AoLa = rhs.AoLa;
    e = rhs.e;
    d = rhs.d;

    return *this;
}
//虚析构函数
RSA_Encrypt::~RSA_Encrypt()
{}

RSA_Encrypt::uint RSA_Encrypt::get_p() const
{
    return p;
}

RSA_Encrypt::uint RSA_Encrypt::get_q() const
{
    return q;
}

RSA_Encrypt::uint RSA_Encrypt::get_n() const
{
    return n;
}

RSA_Encrypt::uint RSA_Encrypt::get_AoLa() const
{
    return AoLa;
}

RSA_Encrypt::uint RSA_Encrypt::get_e() const
{
    return e;
}

int RSA_Encrypt::get_d() const
{
    return d;
}

//判断参数prime是否为素数(素数就是质数)
//质数：质数定义为在大于1的自然数中，除了1和它本身以外不再有其他因数的数称为质数
//参数：一个正整数，判断是否为素数
//返回值：
//   false：不是素数
//   true：是素数
bool RSA_Encrypt::JudgePrime(uint prime)
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

//算出p*q的欧拉值φ(n) = (p-1)(q-1)
//参数：p、q为素数
//      ao_la：欧拉函数的值
//返回值：
//      false：p或者q不为素数
//      true：求出了欧拉值，通过指针参数AoLa返回
bool RSA_Encrypt::CountAoLaNum()
{
    if( !JudgePrime(p) )
    {
        return false;
    }

    if( !JudgePrime(q) )
    {
        return false;
    }
    //求欧拉函数的值
    AoLa = (p - 1)*(q - 1);

    return true;
}

//求两个数的最大公因数(辗转相除法)
//eg:a=25,b=15，a/b=1......10,b/10=1......5,10/5=2.......0,
//最后一个为被除数余数的除数就是5, 5就是所求最大公约数
//e与φ(n)互质,所以最大公因数为1
RSA_Encrypt::uint RSA_Encrypt::CountCommonData(uint a, uint b)
{
    uint c;

    if( c = a%b )
    {
        return CountCommonData(b, c);
    }
    else
    {
        return b;
    }
}

//随机选择公钥e
//随机选择一个整数e，条件是1< e < φ(n) (2 <= e < φ(n))，且e与φ(n)互质；(φ(n)为欧拉函数值)
//（实际应用中，e常常选择65537）
//返回值：
//      false：求随机数失败
//      true：求出了随机数，通过指针参数e返回
//思考是否会栈溢出
bool RSA_Encrypt::RandSelectE()
{
    //为什么欧拉函数AoLa <= 2，因为1< e < φ(n)，如果取值<=2的话，整数e就没有值可以取了
    if(AoLa <= 2)
    {
        return false;
    }

    //初始化随机数发生器
    srand(time(0));

    uint tmp;   //用来临时保存欧拉函数值φ(n)
    do
    {
        //1< e < φ(n)相当于(2 <= e < φ(n))  e为整数
        //要取得[a,b)的随机整数，使用(rand() % (b-a))+ a
        tmp = ((uint)rand() % (AoLa - 2)) + 2;

    //CountCommonData(tmp, AoLa)是为了tmp与AoLa互质(两个质数的最大公因数是1)
    }while( CountCommonData(tmp, AoLa) != 1 );

    e = tmp;

    //测试
    //e = 17;

    return true;
}

//求模反元素
//拓展的欧几里得算法:
//n,m互质
//对于不完全为 0 的非负整数 n，m，gcd（n，m）表示 n，m的最大公约数，
//必然存在整数对 x，y ，使得 gcd（n，m）=ax+by。
//n * x + m * y = 1
int RSA_Encrypt::ExtendedEuclidean(int n, int m, int &x, int &y)
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
//      p、q：随机选择两个不相等的质数p和q
//      n：p和q的乘积n
//      e：随机数e
//      d：模反元素
//返回值：
//      true:  生成密钥成功
//      false: 失败
bool RSA_Encrypt::Produce_RSA_key()
{
    n = p * q;

    int x, y;      //模反元素

    if( CountAoLaNum() )     //算出p*q的欧拉值φ(n) = (p-1)(q-1)
    {
        if( RandSelectE() )     //算出随机数e
        {
            //n * x + m * y = 1
            ExtendedEuclidean(e, AoLa, x, y); //算出模反元素

            //如果x为负，一般把它“正过来”，即再加上AoLa值
            if(x < 0)
            {
                x += AoLa;
            }
            d = x;

            //测试
            //d = 2753;

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
RSA_Encrypt::uint RSA_Encrypt::encrypt(uint m)
{
    uint EncryptInfo = 1;   //加密后的信息

    uint i;
    for( i=0; i < e; ++i)       //=========用了乘的模 等于 模的乘
    {
        EncryptInfo *= m;
        if( EncryptInfo >= n )
        {
            EncryptInfo %= n;
        }
        if(!EncryptInfo)
            return EncryptInfo;
    }
    return EncryptInfo%n;
}

//解密
//公式：cd ≡ m (mod n)
//c的d次方除以n的余数为m
//参数c：待解密的信息
//返回值：解密后的信息
RSA_Encrypt::uint RSA_Encrypt::decrypt(uint c)
{
    uint EncryptInfo = 1;   //解密后的信息

    int i;

    //cout << c << "|" << d << "|" <<  n << endl;
    //问题：模反元素d为负数了
    for( i=0; i < d; ++i)       //=========用了乘的模 等于 模的乘
    {
        EncryptInfo *= c;
        if( EncryptInfo >= n )
        {
            EncryptInfo %= n;
        }
        if(!EncryptInfo)
            return EncryptInfo;
    }
    return EncryptInfo%n;
}














