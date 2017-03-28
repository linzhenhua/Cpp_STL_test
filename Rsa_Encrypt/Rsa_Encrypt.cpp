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

//Ĭ�Ϲ��캯��
//  prime1_��prime2�����ѡ����������ȵ�����
//  product_��prime1_��prime2_�ĳ˻�
//  aola��ŷ������ֵ
//  random_number_�������
//  modular_multiplicative_inverse_��ģ��Ԫ��
RsaEncrypt::RsaEncrypt(const uint &lhs, const uint &rhs)
{
    prime1_ = lhs;
    prime2_ = rhs;
    product_ = 0;
    aola_ = 0;
    random_number_ = 0;
    modular_multiplicative_inverse_ = 0;
}

//���ƹ��캯��
RsaEncrypt::RsaEncrypt(const RsaEncrypt &rhs)
{
    prime1_ = rhs.prime1_;
    prime2_ = rhs.prime2_;
    product_ = rhs.product_;
    aola_ = rhs.aola_;
    random_number_ = rhs.random_number_;
    modular_multiplicative_inverse_ = rhs.modular_multiplicative_inverse_;
}

//����=������
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

//����������
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

//�жϲ���prime�Ƿ�Ϊ����(������������)
//��������������Ϊ�ڴ���1����Ȼ���У�����1�����������ⲻ������������������Ϊ����
//������һ�����������ж��Ƿ�Ϊ����
//����ֵ��
//   false����������
//   true��������
bool RsaEncrypt::JudgePrime(uint prime) const
{
    if(prime == 0)
        return false;

    uint i;

    uint limit = (uint)sqrt( (double)prime );  //������

    for(i = 2; i <= limit; ++i)
    {
        if(prime % i == 0)
        {
            return false;
        }
    }

    return true;
}

//���prime1_ * prime2_��ŷ��ֵ��(n) = (prime1_-1)(prime2_-1)
//������prime1_��prime2_Ϊ����
//      aola_��ŷ��������ֵ
//����ֵ��
//      false��prime1_����prime2_��Ϊ����
//      true�������ŷ��ֵ��ͨ��ָ�����aola_����
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
    //��ŷ��������ֵ
    aola_ = (prime1_ - 1)*(prime2_ - 1);

    return true;
}

//�����������������(շת�����)
//eg:a=25,b=15��a/b=1......10,b/10=1......5,10/5=2.......0,
//���һ��Ϊ�����������ĳ�������5, 5�����������Լ��
//random_number_���(n)����,�����������Ϊ1
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

//���ѡ��Կrandom_number_
//���ѡ��һ������random_number_��������1< random_number_ < ��(n) (2 <= random_number_ < ��(n))��
//��random_number_���(n)���ʣ�(��(n)Ϊŷ������ֵ)
//��ʵ��Ӧ���У�random_number_����ѡ��65537��
//����ֵ��
//      false���������ʧ��
//      true��������������ͨ��ָ�����random_number_����
//˼���Ƿ��ջ���
bool RsaEncrypt::RandSelectRandomNumber()
{
    //Ϊʲôŷ������ֵaoLa_ <= 2����Ϊ1< random_number_ < ��(n)�����ȡֵ<=2�Ļ���
    //����random_number_��û��ֵ����ȡ��
    if(aola_ <= 2)
    {
        return false;
    }

    //��ʼ�������������
    srand(time(0));

    uint tmp;   //������ʱ����ŷ������ֵ��(n)
    do
    {
        //1< random_number_ < ��(n)�൱��(2 <= random_number_ < ��(n))  random_number_Ϊ����
        //Ҫȡ��[a,b)�����������ʹ��(rand() % (b-a))+ a
        tmp = ((uint)rand() % (aola_ - 2)) + 2;

    //CountCommonData(tmp, aola_)��Ϊ��tmp��aola_����(�������������������1)
    }while( CountCommonData(tmp, aola_) != 1 );

    random_number_ = tmp;

    //����
    //random_number_ = 17;

    return true;
}

//��ģ��Ԫ��
//��չ��ŷ������㷨:
//n,m����
//���ڲ���ȫΪ 0 �ķǸ����� n��m��gcd��n��m����ʾ n��m�����Լ����
//��Ȼ���������� x��y ��ʹ�� gcd��n��m��=ax+by��
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

//����RSA����˽��Կ
//������
//      prime1_��prime2_�����ѡ����������ȵ�����
//      product_��prime1_��prime1_�ĳ˻�product_
//      random_number_�������random_number_
//      modular_multiplicative_inverse_��ģ��Ԫ��
//����ֵ��
//      true:  ������Կ�ɹ�
//      false: ʧ��
bool RsaEncrypt::ProduceRsaKey()
{
    product_ = prime1_ * prime2_;

    int x, y;      //ģ��Ԫ��

    if( CountAolaNum() )     //���p*q��ŷ��ֵ��(n) = (p-1)(q-1)
    {
        if( RandSelectRandomNumber() )     //��������random_number_
        {
            //n * x + m * y = 1
            ExtendedEuclidean(random_number_, aola_, x, y); //���ģ��Ԫ��

            //���xΪ����һ��������������������ټ���AoLaֵ
            if(x < 0)
            {
                x += aola_;
            }
            modular_multiplicative_inverse_ = x;

            //����
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

//����
//��ʽ��me �� c (mod n)
//m��e�η�����n������Ϊc
//����m�������ܵ���Ϣ
//����ֵ�����ܺ����Ϣ
RsaEncrypt::uint RsaEncrypt::Encrypt(uint m) const
{
    uint EncryptInfo = 1;   //���ܺ����Ϣ

    uint i;
    for( i=0; i < random_number_; ++i)       //=========���˳˵�ģ ���� ģ�ĳ�
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

//����
//��ʽ��cd �� m (mod n)
//c��d�η�����n������Ϊm
//����c�������ܵ���Ϣ
//����ֵ�����ܺ����Ϣ
RsaEncrypt::uint RsaEncrypt::Decrypt(uint c) const
{
    uint EncryptInfo = 1;   //���ܺ����Ϣ

    int i;

    //cout << c << "|" << d << "|" <<  n << endl;
    for( i=0; i < modular_multiplicative_inverse_; ++i)       //=========���˳˵�ģ ���� ģ�ĳ�
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
