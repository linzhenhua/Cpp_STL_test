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

//Ĭ�Ϲ��캯��
//  p��q�����ѡ����������ȵ�����p��q
//  n��p��q�ĳ˻�n
//  AoLa��ŷ������ֵ
//  e�������e
//  d��ģ��Ԫ��
RSA_Encrypt::RSA_Encrypt(const uint &a, const uint &b)
{
    p = a;
    q = b;
    n = 0;
    AoLa = 0;
    e = 0;
    d = 0;
}

//���ƹ��캯��
RSA_Encrypt::RSA_Encrypt(const RSA_Encrypt &rhs)
{
    p = rhs.p;
    q = rhs.q;
    n = rhs.n;
    AoLa = rhs.AoLa;
    e = rhs.e;
    d = rhs.d;
}

//����=������
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
//����������
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

//�жϲ���prime�Ƿ�Ϊ����(������������)
//��������������Ϊ�ڴ���1����Ȼ���У�����1�����������ⲻ������������������Ϊ����
//������һ�����������ж��Ƿ�Ϊ����
//����ֵ��
//   false����������
//   true��������
bool RSA_Encrypt::JudgePrime(uint prime)
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

//���p*q��ŷ��ֵ��(n) = (p-1)(q-1)
//������p��qΪ����
//      ao_la��ŷ��������ֵ
//����ֵ��
//      false��p����q��Ϊ����
//      true�������ŷ��ֵ��ͨ��ָ�����AoLa����
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
    //��ŷ��������ֵ
    AoLa = (p - 1)*(q - 1);

    return true;
}

//�����������������(շת�����)
//eg:a=25,b=15��a/b=1......10,b/10=1......5,10/5=2.......0,
//���һ��Ϊ�����������ĳ�������5, 5�����������Լ��
//e���(n)����,�����������Ϊ1
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

//���ѡ��Կe
//���ѡ��һ������e��������1< e < ��(n) (2 <= e < ��(n))����e���(n)���ʣ�(��(n)Ϊŷ������ֵ)
//��ʵ��Ӧ���У�e����ѡ��65537��
//����ֵ��
//      false���������ʧ��
//      true��������������ͨ��ָ�����e����
//˼���Ƿ��ջ���
bool RSA_Encrypt::RandSelectE()
{
    //Ϊʲôŷ������AoLa <= 2����Ϊ1< e < ��(n)�����ȡֵ<=2�Ļ�������e��û��ֵ����ȡ��
    if(AoLa <= 2)
    {
        return false;
    }

    //��ʼ�������������
    srand(time(0));

    uint tmp;   //������ʱ����ŷ������ֵ��(n)
    do
    {
        //1< e < ��(n)�൱��(2 <= e < ��(n))  eΪ����
        //Ҫȡ��[a,b)�����������ʹ��(rand() % (b-a))+ a
        tmp = ((uint)rand() % (AoLa - 2)) + 2;

    //CountCommonData(tmp, AoLa)��Ϊ��tmp��AoLa����(�������������������1)
    }while( CountCommonData(tmp, AoLa) != 1 );

    e = tmp;

    //����
    //e = 17;

    return true;
}

//��ģ��Ԫ��
//��չ��ŷ������㷨:
//n,m����
//���ڲ���ȫΪ 0 �ķǸ����� n��m��gcd��n��m����ʾ n��m�����Լ����
//��Ȼ���������� x��y ��ʹ�� gcd��n��m��=ax+by��
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

//����RSA����˽��Կ
//������
//      p��q�����ѡ����������ȵ�����p��q
//      n��p��q�ĳ˻�n
//      e�������e
//      d��ģ��Ԫ��
//����ֵ��
//      true:  ������Կ�ɹ�
//      false: ʧ��
bool RSA_Encrypt::Produce_RSA_key()
{
    n = p * q;

    int x, y;      //ģ��Ԫ��

    if( CountAoLaNum() )     //���p*q��ŷ��ֵ��(n) = (p-1)(q-1)
    {
        if( RandSelectE() )     //��������e
        {
            //n * x + m * y = 1
            ExtendedEuclidean(e, AoLa, x, y); //���ģ��Ԫ��

            //���xΪ����һ��������������������ټ���AoLaֵ
            if(x < 0)
            {
                x += AoLa;
            }
            d = x;

            //����
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

//����
//��ʽ��me �� c (mod n)
//m��e�η�����n������Ϊc
//����m�������ܵ���Ϣ
//����ֵ�����ܺ����Ϣ
RSA_Encrypt::uint RSA_Encrypt::encrypt(uint m)
{
    uint EncryptInfo = 1;   //���ܺ����Ϣ

    uint i;
    for( i=0; i < e; ++i)       //=========���˳˵�ģ ���� ģ�ĳ�
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

//����
//��ʽ��cd �� m (mod n)
//c��d�η�����n������Ϊm
//����c�������ܵ���Ϣ
//����ֵ�����ܺ����Ϣ
RSA_Encrypt::uint RSA_Encrypt::decrypt(uint c)
{
    uint EncryptInfo = 1;   //���ܺ����Ϣ

    int i;

    //cout << c << "|" << d << "|" <<  n << endl;
    //���⣺ģ��Ԫ��dΪ������
    for( i=0; i < d; ++i)       //=========���˳˵�ģ ���� ģ�ĳ�
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














