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
#include "key_produce.h"

using namespace std;

int main()
{
    RSA_Encrypt rsa(61, 53);

    rsa.Produce_RSA_key();

    cout << "rsa.get_p(): " << rsa.get_p() << endl;
    cout << "rsa.get_q(): " << rsa.get_q() << endl;
    cout << "rsa.get_n(): " << rsa.get_n() << endl;
    cout << "rsa.get_e(): " << rsa.get_e() << endl;
    cout << "rsa.get_d(): " << rsa.get_d() << endl;
    cout << "rsa.get_AoLa: " << rsa.get_AoLa() << endl;

    unsigned int EncryptInfo;   //加密后的信息
    EncryptInfo = rsa.encrypt(65);
    cout << "EncryptInfo: " << EncryptInfo << endl;

    unsigned int DecryptInfo;   //解密后的信息
    DecryptInfo = rsa.decrypt(EncryptInfo);
    cout << "DecryptInfo: " << DecryptInfo << endl;


    return 0;
}
