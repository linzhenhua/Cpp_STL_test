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

#include "rsa_encrypt.h"
#include "big_number.h"
#include "large_number.h"

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

    //公钥(product,random_number) 只能加密小于product的整数
    unsigned int EncryptInfo;   //加密后的信息
    EncryptInfo = rsa.Encrypt(3232);
    cout << "EncryptInfo: " << EncryptInfo << endl;

    unsigned int DecryptInfo;   //解密后的信息
    DecryptInfo = rsa.Decrypt(EncryptInfo);
    cout << "DecryptInfo: " << DecryptInfo << endl;

    BigNumber big_number1("123");
    BigNumber big_number2("3");
    BigNumber big_number3("");

    big_number3 = big_number1 + big_number2;
    big_number3.print();

    big_number3 = big_number1 - big_number2;
    big_number3.print();

    big_number3 = big_number1 * big_number2;
    big_number3.print();

    return 0;
}
