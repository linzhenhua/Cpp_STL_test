/******************************************************************************
*    > File Name: large_number.h
*
*    >Description:
*
*    >Version: 1.0
*    >Created Time: 20170329
*    >Revision: none
*    >Compiler: gcc
*
*    > Author: linzhenhua
*    > Mail: linzhenhualzh@163.com
*    > Company:
*
******************************************************************************/
#ifndef LARGE_NUMBER_H
#define LARGE_NUMBER_H

#include <string>

using namespace std;

class LargeNumber{
public:
    //默认构造函数
    LargeNumber();
    //复制构造函数
    LargeNumber(const LargeNumber &rhs);
    //重载=号操作符
    LargeNumber& operator=(const LargeNumber &rhs);
    //析构函数
    ~LargeNumber();

    //将大数赋值给另外一个大数
    LargeNumber& Mov(LargeNumber& rhs);

    //比较两个大数大小
    int Cmp(LargeNumber &rhs);

    //计算两个大数的和
    LargeNumber Add(LargeNumber &rhs);

    //计算两个大数的差
    LargeNumber Sub(LargeNumber& rhs);

    //计算两个大数的积
    LargeNumber Mul(LargeNumber& rhs);

    //计算两个大数的商
    LargeNumber Div(LargeNumber& rhs);

    //计算两个大数相除的余数
    LargeNumber Mod(LargeNumber& rhs);

    //将输入的10进制或16进制字符串转换成大数
    int InPutFromStr(string& str, const unsigned int system = k_dec_);

    //将大数按10进制或16进制格式输出到字符串
    int OutPutToStr(string& str, const unsigned int system = k_dec_);

    //欧几里德算法求(二元一次方程解)：Y=X.Euc(A)，使满足：YX mod A = 1
    LargeNumber Euc(LargeNumber& rhs);

    //蒙哥马利算法求(幂模运算)：Y=X.Mon(A,B)，使满足：X^A mod B = Y
    LargeNumber Mon(LargeNumber& lhs, LargeNumber& rhs);

private:
    static const int k_large_number_maxlen_ = 40;            //10进制位的最大位数
    static const unsigned int k_dec_ = 10;                   //表示10进制
    static const unsigned int k_hex_ = 16;                   //表示16进制

    int sign_;    //记录大数的符号，支持负值运算
    int length_;  //记录0x10000000进制的位数，0-40之间，相当于2进制的0-1280位
    unsigned long value_[k_large_number_maxlen_];   //记录每一位的“数字”
};

#endif // LARGE_NUMBER_H
