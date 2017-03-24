/******************************************************************************
*    > File Name: main.cpp
*
*    >Description:
*
*    >Version: 1.0
*    > Created Time: 20170316
*    >Revision: none
*    >Compiler: gcc
*
*    > Author: linzhenhua
*    > Mail: linzhenhualzh@163.com
*    > Company:
*
******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Rsa_Encrypt.h"

using namespace std;

int main()
{
    RsaEncrypt rsa(61, 53);

    rsa.ProduceRsaKey();

    cout << "rsa.get_prime1(): " << rsa.get_prime1() << endl;
    cout << "rsa.get_prime2(): " << rsa.get_prime2() << endl;
    cout << "rsa.get_product(): " << rsa.get_product() << endl;
    cout << "rsa.get_random_number(): " << rsa.get_random_number() << endl;
    cout << "rsa.get_modular_multiplicative_inverse(): " << rsa.get_modular_multiplicative_inverse() << endl;
    cout << "rsa.get_aoLa: " << rsa.get_aoLa() << endl;

    //��Կ(product,random_number) ֻ�ܼ���С��product������
    unsigned int EncryptInfo;   //���ܺ����Ϣ
    EncryptInfo = rsa.Encrypt(3232);
    cout << "EncryptInfo: " << EncryptInfo << endl;

    unsigned int DecryptInfo;   //���ܺ����Ϣ
    DecryptInfo = rsa.Decrypt(EncryptInfo);
    cout << "DecryptInfo: " << DecryptInfo << endl;

    return 0;
}
