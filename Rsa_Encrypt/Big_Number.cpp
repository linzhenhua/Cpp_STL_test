/******************************************************************************
*    > File Name: big_number.cpp
*
*    >Description:
*
*    >Version: 1.0
*    >Created Time: 20170324
*    >Revision: none
*    >Compiler: gcc
*
*    > Author: linzhenhua
*    > Mail: linzhenhualzh@163.com
*    > Company:
*
******************************************************************************/
#include<cstdlib>
#include<cstdio>
#include<cstring>

#include<iostream>

#include "big_number.h"

//默认构造函数
BigNumber::BigNumber(const string &str)
{
    big_number_ = str;
}

//复制构造函数
BigNumber::BigNumber(const BigNumber &rhs)
{
    big_number_ = rhs.big_number_;
}

//重载=操作符
BigNumber& BigNumber::operator=(const BigNumber &rhs)
{
    big_number_ = rhs.big_number_;

    return *this;
}

//析构函数
BigNumber::~BigNumber()
{}

//重载加法运算符
//方法：
//      默认两个整数都是正整数
//参数：
//      待相加的参数
//返回值：
//      相加后的值
BigNumber operator+(const BigNumber &lhs, const BigNumber &rhs)
{
    int up;    //进位
    int i, j;

    int len1 = lhs.big_number_.length();
    int len2 = rhs.big_number_.length();

    int arr1[BigNumber::k_max_];
    int arr2[BigNumber::k_max_];

    //把数组初始化为0
    memset(arr1, 0, sizeof(arr1));
    memset(arr2, 0, sizeof(arr2));

    //倒序保存字符串
    for(i = len1 - 1, j = 0; i >= 0; --i)
    {
        arr1[j] = lhs.big_number_[i] - '0';   //将字符转换为整数保存

        j++;
    }

    for(i = len2 - 1, j = 0; i >= 0; --i)
    {
        arr2[j] = rhs.big_number_[i] - '0';

        j++;
    }

    //大数相加，相加后保存到数组arr1里
    for(i = 0, up = 0; i < BigNumber::k_max_; ++i)
    {
        arr1[i] = arr1[i] + arr2[i] + up;

        up = arr1[i] / 10;                  //判断是否有进位
        arr1[i] %= 10;
    }

    BigNumber ret_temp("");

    char buffer;
    //求出倒序数组arr1里，第一个不为0的位置，比如：135000(实际数字是531)，第一个不为0的位置就是5
    for (i = BigNumber::k_max_ - 1; i >= 0; --i)
    {
        if (arr1[i])
        {
            break;
        }
    }
    //cout << arr1[i] << endl;   //2
    for (j = i; j >= 0; --j)
    {
        sprintf(&buffer, "%d", arr1[j]);

        ret_temp.big_number_.push_back(buffer);
    }

    return ret_temp;
}

//重载减法运算符
//备注：
//      默认两个整数都是正整数，被减数大于减数
//方法：
//      切记退位
//参数：
//      待相减的参数
//返回值：
//      相减后的值
BigNumber operator-(const BigNumber &lhs, const BigNumber &rhs)
{
    int down;    //退位
    int i, j;

    int len1 = lhs.big_number_.length();
    int len2 = rhs.big_number_.length();

    int arr1[BigNumber::k_max_];
    int arr2[BigNumber::k_max_];

    //把数组初始化为0
    memset(arr1, 0, sizeof(arr1));
    memset(arr2, 0, sizeof(arr2));

    //倒序保存字符串
    for(i = len1 - 1, j = 0; i >= 0; --i)
    {
        arr1[j] = lhs.big_number_[i] - '0';   //将字符转换为整数保存
        j++;
    }

    for(i = len2 - 1, j = 0; i >= 0; --i)
    {
        arr2[j] = rhs.big_number_[i] - '0';
        j++;
    }

    //大数相减，相减后保存到数组arr1里
    int temp;
    for(i = 0, down = 0; i < BigNumber::k_max_; ++i)
    {
        if(arr1[i] >= arr2[i])
        {
            arr1[i] = arr1[i] - arr2[i] - down;
            down = 0;
        }
        else
        {
            temp = arr1[i] + 10 - down;     //借位
            down = 1;
            arr1[i] = temp - arr2[i];
        }
    }

    BigNumber ret_temp("");

    char buffer;
    //求出倒序数组arr1里，第一个不为0的位置，比如：135000(实际数字是531)，第一个不为0的位置就是5
    for (i = BigNumber::k_max_ - 1; i >= 0; --i)
    {
        if (arr1[i])
        {
            break;
        }
    }

    for (j = i; j >= 0; --j)
    {
        sprintf(&buffer, "%d", arr1[j]);

        ret_temp.big_number_.push_back(buffer);
    }

    return ret_temp;
}

//重载乘法运算符
//备注：
//      默认两个整数都是正整数
//方法：
//
//参数：
//      待相乘的参数
//返回值：
//      相乘后的值
BigNumber operator*(const BigNumber &lhs, const BigNumber &rhs)
{
    int i, j;

    int len1 = lhs.big_number_.length();
    int len2 = rhs.big_number_.length();

    int arr1[BigNumber::k_max_];
    int arr2[BigNumber::k_max_];
    int arr3[BigNumber::k_max_];

    //把数组初始化为0
    memset(arr1, 0, sizeof(arr1));
    memset(arr2, 0, sizeof(arr2));
    memset(arr3, 0, sizeof(arr3));

    //倒序保存字符串
    for(i = len1 - 1, j = 0; i >= 0; --i)
    {
        arr1[j] = lhs.big_number_[i] - '0';   //将字符转换为整数保存
        j++;
    }

    for(i = len2 - 1, j = 0; i >= 0; --i)
    {
        arr2[j] = rhs.big_number_[i] - '0';
        j++;
    }

    //相乘
    for(i = 0; i < len1; ++i)
    {
        for(j = 0; j < len2; ++j)
        {
            arr3[i+j] += arr1[i] * arr2[j];
        }
    }

    int len3 = len1 + len2;
    for(i = 0; i < len3; ++i)
    {
        arr3[i+1] += arr3[i] / 10;
        arr3[i] %= 10;
    }

    BigNumber ret_temp("");

    char buffer;
    //求出倒序数组arr3里，第一个不为0的位置，比如：135000(实际数字是531)，第一个不为0的位置就是5
    for (i = BigNumber::k_max_ - 1; i >= 0; --i)
    {
        if (arr3[i])
        {
            break;
        }
    }

    for (j = i; j >= 0; --j)
    {
        sprintf(&buffer, "%d", arr3[j]);

        ret_temp.big_number_.push_back(buffer);
    }

    return ret_temp;
}


//除法
BigNumber operator/(const BigNumber &lhs, const BigNumber &rhs)
{

}

