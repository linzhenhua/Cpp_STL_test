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

//RSA�ӽ���
class RsaEncrypt{
public:
    typedef unsigned int uint;

    //Ĭ�Ϲ��캯��
    RsaEncrypt(const uint &lhs, const uint &rhs);

    //���ƹ��캯��
    RsaEncrypt(const RsaEncrypt &rhs);

    //����=������
    RsaEncrypt& operator=(const RsaEncrypt &rhs);

    virtual ~RsaEncrypt();   //����������

public:
    uint get_prime1() const;
    uint get_prime2() const;
    uint get_product() const;
    uint get_aoLa() const;
    uint get_random_number() const;
    int get_modular_multiplicative_inverse() const;

    //����RSA����˽��Կ
    bool ProduceRsaKey();

    //����
    uint Encrypt(uint m) const;

    //����
    uint Decrypt(uint c) const;

private:
    //�жϲ���prime�Ƿ�Ϊ����(������������)
    bool JudgePrime(uint prime) const;

    //���prime1_ * prime2_��ŷ��ֵAoLa
    bool CountAolaNum();

    //�����������������
    uint CountCommonData(uint a, uint b) const;

    //���ѡ��һ����
    bool RandSelectRandomNumber();

    //��ģ��Ԫ��
    int ExtendedEuclidean(int n, int m, int &x, int &y) const;

private:
    //prime1_��prime2_�����ѡ����������ȵ�����
    uint prime1_;
    uint prime2_;

    //product_��prime1_��prime2_�ĳ˻�product_
    uint product_;

    //aola_��ŷ������ֵ
    uint aola_;

    //random_number_�������
    uint random_number_;

    //modular_multiplicative_inverse_��ģ��Ԫ��
    int modular_multiplicative_inverse_;
};

#endif // RSA_ENCRYPT_H
