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

    //Ĭ�Ϲ��캯��
    RSA_Encrypt(const uint &a, const uint &b);

    //���ƹ��캯��
    RSA_Encrypt(const RSA_Encrypt &rhs);

    //����=������
    RSA_Encrypt& operator=(const RSA_Encrypt &rhs);

    virtual ~RSA_Encrypt();   //����������

public:
    uint get_p() const;
    uint get_q() const;
    uint get_n() const;
    uint get_AoLa() const;
    uint get_e() const;
    int get_d() const;

    //����RSA����˽��Կ
    bool Produce_RSA_key();

    //����
    uint encrypt(uint m);

    //����
    uint decrypt(uint c);

private:
    //�жϲ���prime�Ƿ�Ϊ����(������������)
    bool JudgePrime(uint prime);

    //���p*q��ŷ��ֵAoLa
    bool CountAoLaNum();

    //�����������������
    uint CountCommonData(uint a, uint b);

    //���ѡ��Կe
    bool RandSelectE();

    //��ģ��Ԫ��
    int ExtendedEuclidean(int n, int m, int &x, int &y);

private:
    //p��q�����ѡ����������ȵ�����p��q
    uint p;
    uint q;

    //n��p��q�ĳ˻�n
    uint n;

    //AoLa��ŷ������ֵ
    uint AoLa;

    //e�������e
    uint e;

    //d��ģ��Ԫ��
    int d;
};

#endif // CKEY_PRODUCE_H
