/******************************************************************************
*    > File Name: large_number.cpp
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
#include<cstdlib>
#include<cstring>

#include "large_number.h"

//Ĭ�Ϲ��캯��
LargeNumber::LargeNumber()
{
    sign_ = 1;
    length_ = 1;
    memset(value_, 0, sizeof(value_));
}

//���ƹ��캯��
LargeNumber::LargeNumber(const LargeNumber &rhs)
{
    sign_ = rhs.sign_;
    length_ = rhs.length_;
    memcpy(value_, rhs.value_, sizeof(rhs.value_));
}

//����=�Ų�����
LargeNumber& LargeNumber::operator=(const LargeNumber &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }

    sign_ = rhs.sign_;
    length_ = rhs.length_;
    memcpy(value_, rhs.value_, sizeof(rhs.value_));

    return *this;
}

//��������
LargeNumber::~LargeNumber()
{}

//�հ�����ĸ�����
LargeNumber& LargeNumber::Mov(LargeNumber& rhs)
{
    length_ = rhs.length_;
    memcpy(value_, rhs.value_, sizeof(rhs.value_));

    return *this;
}

//�����Ƚϣ��������Aλ���ȴ���B�࣬��ȻA>B
//���λ����ͬ����Ӹ�λ��ʼ�Ƚϣ�ֱ���ֳ���С
//����ֵ��
//  1������
//  -1��С��
//  0������
int LargeNumber::Cmp(LargeNumber &rhs)
{
    if(length_ > rhs.length_)
    {
        return 1;
    }

    if(length_ < rhs.length_)
    {
        return -1;
    }

    for(int i = length_ - 1; i >= 0; --i)
    {
        if(value_[i] > rhs.value_[i])
        {
            return 1;
        }
        if(value_[i] < rhs.value_[i])
        {
            return -1;
        }
    }

    return 0;
}

//�������
//������ʽ��N.Add(A)������ֵ��N+A
//��������������ͬ����ֵ��ӣ�����ı���������ٵ��ô����������
/******************************************************************
���磺
     A  B  C
+       D  E
--------------
= S  F  G  H

���У���C+E<=0xffffffff����H=C+E��carry(��λ��־)=0
     ��C+E>0xffffffff����H=C+E-0x100000000��carry=1

     ��B+D+carry<=0xfffffff����G=B+D��carry=0
     ��B+D+carry>0xfffffff����G=B+D+carry-0x10000000��carry=1

     ��carry=0����F=A��S=0
     ��carry=1��A<0xfffffff����F=A+1��S=0
     ��carry=1��A=0xfffffff����F=0��S=1
*****************************************************************/
LargeNumber LargeNumber::Add(LargeNumber &rhs)
{
    LargeNumber large_number;

    if(large_number.sign_ == rhs.sign_)
    {
        large_number = *this;
        int carry = 0;
        unsigned long long sum = 0;
        if(large_number.length_ < rhs.length_)
        {
            large_number.length_ = rhs.length_;
        }

        for(int i = 0; i < large_number.length_; ++i)
        {
            sum = rhs.value_[i];
            sum = sum + large_number.value_[i] + carry;
            large_number.value_[i] = (unsigned long)sum;
            if(sum > 0xffffffff)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
        }

        if(large_number.length_ < k_large_number_maxlen_)
        {
            large_number.value_[length_] = carry;
            large_number.length_ += carry;
        }
        return large_number;
    }
    else
    {
        large_number.Mov(rhs);
        large_number.sign_ = 1 - large_number.sign_;
        return Sub(large_number);
    }
}

//�������
//������ʽ��N.Sub(A)������ֵ��N-A
//��������������ͬ����ֵ���������ı���������ٵ��ô�����Ӻ���(��������)
/******************************************************************
���磺
     A  B  C
-       D  E
--------------
=    F  G  H

���У���C>=E����H=C-E��carry(��λ��־)=0
     ��C<E����H=C-E+0x100000000��carry=1

     ��B-carry>=D����G=B-carry-D��carry=0
     ��B-carry<D����G=B-carry-D+0x10000000��carry=1

     ��carry=0����F=A
     ��carry=1��A>1����F=A-1
     ��carry=1��A=1����F=0
*****************************************************************/
LargeNumber LargeNumber::Sub(LargeNumber& rhs)
{
	LargeNumber large_number;

	if( sign_ == rhs.sign_ )                //������ͬ
	{
		//large_number.Mov(*this);
        large_number = *this;

		int cmp = large_number.Cmp(rhs);    //�Ƚ��������Ĵ�С
		if( cmp == 0 )                      //���������
		{
			large_number.sign_ = 1;
			large_number.length_ = 1;
			memset( large_number.value_, 0, sizeof(large_number.value_) );

			return large_number;
		}

		int len, carry = 0;
		unsigned long long num;
		unsigned long *s, *d;

        if( cmp > 0 )
        {
            s = large_number.value_;
            d = rhs.value_;
            len = large_number.length_;
        }

		if( cmp < 0 )
		{
			s = rhs.value_;
			d = large_number.value_;
			len = rhs.length_;
			large_number.sign_ = 1 - large_number.sign_;
		}

		for( int i = 0; i < len; ++i )
		{
			if( (s[i]-carry) >= d[i] )
			{
				large_number.value_[i] = s[i] - carry - d[i];
				carry = 0;
			}
			else
			{
				num = 0x100000000 + s[i];
				large_number.value_[i] = (unsigned long)(num - carry - d[i]);
				carry=1;
			}
		}

		while( large_number.value_[len-1] == 0 )
		{
			len--;
		}

		large_number.length_ = len;
		return large_number;
	}
	else
	{
		large_number.Mov(rhs);
		large_number.sign_ = 1 - large_number.sign_;
		return Add(large_number);
	}
}

//�������
//������ʽ��N.Mul(A)������ֵ��N*A
/******************************************************************
���磺
        A  B  C
*          D  E
----------------
=    S  F  G  H
+ T  I  J  K
----------------
= U  V  L  M  N

���У�SFGH=ABC*E��TIJK=ABC*D

�����ڣ�
     A  B  C
*          E
-------------
= S  F  G  H

���У���C*E<=0xffffffff����H=C*E��carry(��λ��־)=0
      ��C*E>0xffffffff����H=(C*E)&0xffffffff
      carry=(C*E)/0xffffffff
      ��B*E+carry<=0xffffffff����G=B*E+carry��carry=0
      ��B*E+carry>0xffffffff����G=(B*E+carry)&0xffffffff
      carry=(B*E+carry)/0xffffffff
      ��A*E+carry<=0xffffffff����F=A*E+carry��carry=0
      ��A*E+carry>0xffffffff����F=(A*E+carry)&0xffffffff
      carry=(A*E+carry)/0xffffffff
      S=carry
*****************************************************************/
LargeNumber LargeNumber::Mul(LargeNumber& rhs)
{
	LargeNumber large_number1, large_number2;
	unsigned long long mul;
    unsigned long carry;

    for(int i = 0; i < rhs.length_; ++i)
	{
		large_number2.length_ = length_;
		carry = 0;

		for(int j = 0; j < length_; ++j)
		{
			mul = value_[j];
			mul = mul * rhs.value_[i] + carry;
			large_number2.value_[j] = (unsigned long)mul;
			carry = (unsigned long)(mul >> 32);
		}

		if( carry && (large_number2.length_ < k_large_number_maxlen_) )
	    {
			large_number2.length_++;
			large_number2.value_[large_number2.length_ - 1] = carry;

			if( large_number2.length_ < k_large_number_maxlen_ - i )
			{
				large_number2.length_ += i;
				for(int k = large_number2.length_-1; k >= i; k--)
				{
					large_number2.value_[k] = large_number2.value_[k-i];
				}
				for(int k = 0; k < i; k++)
				{
					large_number2.value_[k] = 0;
				}
			}
			large_number1.Mov( large_number1.Add( large_number2 ) );
		}

		if(sign_ + rhs.sign_ == 1 )
		{
			large_number1.sign_ = 0;
		}
		else
		{
			large_number1.sign_ = 1;
		}
		return large_number1;
	}
}

//�������
//������ʽ��N.Div(A)������ֵ��N/A
//�����Ĺؼ����ڡ����̡���Ȼ��ͱ���˳˷��ͼ���
//���ｫ�����������������ת�����˱��������λ��������λ������
LargeNumber LargeNumber::Div(LargeNumber& rhs)
{
	LargeNumber large_number1, large_number2, large_number3;
	int len;
	unsigned long long num, div;
	unsigned long carry = 0;

	large_number2.Mov(*this);

	while(large_number2.Cmp(rhs) > 0)
	{
		if( large_number2.value_[large_number2.length_ - 1] > rhs.value_[rhs.length_ - 1] )
		{
			len = large_number2.length_ - rhs.length_;
			div = large_number2.value_[large_number2.length_ - 1] / (rhs.value_[rhs.length_ - 1] + 1);
		}
		else if(large_number2.length_ > rhs.length_)
		{
			len = large_number2.length_ - rhs.length_ - 1;
			num = large_number2.value_[large_number2.length_ - 1];
			num = (num << 32) + large_number2.value_[large_number2.length_ - 2];
			if(rhs.value_[rhs.length_ - 1] == 0xffffffff)
			{
				div = ( num >> 32 );
			}
			else
			{
				div = num / (rhs.value_[rhs.length_ - 1] + 1);
			}
		}
		else
		{
			large_number1.Mov(large_number1.Add(1));
			break;
		}

		large_number3.Mov(div);
		large_number3.length_ += len;

		for(int i = large_number3.length_ - 1; i >= len; --i)
		{
			large_number3.value_[i] = large_number3.value_[i-len];
		}

		for(int i = 0; i < len; ++i)
		{
			large_number3.value_[i] = 0;
		}
		large_number1.Mov( large_number1.Add(large_number3) );
		large_number3.Mov( large_number3.Mul(rhs) );
		large_number2.Mov( large_number2.Sub(large_number3) );
	}

	if(large_number2.Cmp(rhs) == 0)
	{
		large_number1.Mov( large_number1.Add(1) );
	}

	if(m_nSign+rhs.m_nSign == 1)
	{
		large_number1.m_nSign = 0;
	}
	else
	{
		large_number1.m_nSign = 1;
	}

	return large_number1;
}

//������ģ
//������ʽ��N.Mod(A)������ֵ��N%A
//��ģ������ԭ����ͬ
LargeNumber LargeNumber::Mod(LargeNumber& rhs)
{
	LargeNumber large_number1, large_number2;
	int len;
	unsigned long long num, div;
	//unsigned long carry = 0;

	large_number1.Mov(*this);

	while( large_number1.Cmp(rhs) > 0 )
	{
		if( large_number1.value_[large_number1.length_ - 1] > rhs.value_[rhs.length_ - 1])
		{
			len = large_number1.length_-rhs.length_;
			div = large_number1.value_[large_number1.length_ - 1] / (rhs.value_[rhs.length_ - 1] + 1);
		}
		else if( large_number1.length_ > rhs.length_ )
		{
			len = large_number1.length_ - rhs.length_ - 1;
			num = large_number1.value_[large_number1.length_ - 1];
			num = ( num << 32 ) + large_number1.value_[large_number1.length_ - 2];
			if(rhs.value_[rhs.length_ - 1] == 0xffffffff)
			{
				div = ( num >> 32 );
			}
			else
			{
				div = num / ( rhs.value_[rhs.length_ - 1] + 1 );
			}
		}
		else
		{
			large_number1.Mov(large_number1.Sub(rhs));
			break;
		}

		large_number2.Mov( div );
		large_number2.Mov( large_number2.Mul( rhs ) );
		large_number2.length_ += len;

		for(int i = large_number2.length_ - 1; i >= len; --i)
		{
			large_number2.value_[i] = large_number2.value_[i - len];
		}
		for(int i = 0; i < len; ++i)
		{
			large_number2.value_[i] = 0;
		}
		large_number1.Mov( large_number1.Sub( large_number2 ) );
	}

	if(large_number1.Cmp(rhs)==0)
	{
		large_number1.Mov(0);
	}

	return large_number1;
}

//��ʱֻ������ʮ�����ַ�����ת��
int LargeNumber::InPutFromStr(string& str, const unsigned int system = k_dec_)
{
    int len=str.length();

	Mov(0);
	for(int i=0; i < len; ++i)
    {
		Mov(Mul(system));
		int k = str[i] - 48;
		Mov( Add(k) );
	}

	return 0;
}

//��ʱֻ������ʮ�����ַ�����ת��
int LargeNumber::OutPutToStr(string& str, const unsigned int system = k_dec_)
{
	str="";
	char ch;
	LargeNumber large_number;

	large_number.Mov(*this);

	while( large_number.value_[large_number.length_ - 1] > 0 )
	{
		ch = large_number.Mod(system) + 48;
		str.insert(0,&ch);
		large_number.Mov(large_number.Div(system));
	}

	return 0;
}

//ŷ������㷨��Y=X.Euc(A)��ʹ���㣺YX mod A=1
//�൱�ڶԲ�������ax-by=1����С������
//ʵ���Ͼ��ǳ���ѧ����շת�����
/********************************************************************
���磺11x-49y=1����x

           11 x  -  49 y  =   1      a)
49%11=5 ->  11 x  -   5 y  =   1      b)
11%5 =1 ->     x  -   5 y  =   1      c)

��y=1  ����c)ʽ  ��x=6
��x=6  ����b)ʽ  ��y=13
��y=13 ����a)ʽ  ��x=58
********************************************************************/
LargeNumber LargeNumber::Euc(LargeNumber& rhs)
{
	LargeNumber large_number1,large_number2;

	large_number1.Mov(*this);
	large_number2.Mov(rhs);

	if( ( large_number1.length_ == 1 ) && ( large_number1.value_[0] == 1 ) )
	{
		return large_number1;
	}

	if(( large_number2.length_ == 1 ) && ( large_number2.value_[0] == 1 ) )
	{
		large_number1.Mov( large_number1.Sub(1) );
		return large_number1;
	}

	if(large_number1.Cmp(large_number2) == 1)
	{
		large_number1.Mov( large_number1.Mod(large_number2) );
	}
	else
	{
		large_number2.Mov( large_number2.Mod(large_number1) );
	}

	large_number1.Mov( large_number1.Euc( large_number2 ) );
    large_number2.Mov(*this);

	if(large_number2.Cmp(rhs) == 1)
	{
		large_number1.Mov( large_number1.Mul(large_number2) );
		large_number1.Mov( large_number1.Sub(1) );
		large_number1.Mov( large_number1.Div(rhs) );
	}
	else
	{
		large_number1.Mov( large_number1.Mul(rhs) );
		large_number1.Mov( large_number1.Add(1) );
		large_number1.Mov( large_number1.Div(large_number2) );
	}

	return large_number1;
}

//�ɸ������㷨��Y=X.Mon(A,B)��ʹ���㣺X^A mod B=Y
//�����ƾ��Ǹ���ѧ���ķ���ƽ����
LargeNumber LargeNumber::Mon(LargeNumber& lhs, LargeNumber& rhs)
{
	LargeNumber large_number1, large_number2, large_number3;

	large_number1.Mov(1);
	large_number2.Mov(*this);
	large_number3.Mov(lhs);

	while( (large_number3.length_ != 1 ) || large_number3.value_[0] )
	{
		if(large_number3.value_[0] & 1)
		{
			large_number3.Mov(large_number3.Sub(1));
			large_number1.Mov(large_number1.Mul(large_number2));
			large_number1.Mov(large_number1.Mod(rhs));
		}
		else
		{
			large_number3.Mov(large_number3.Div(2));
			large_number2.Mov(large_number2.Mul(large_number2));
			large_number2.Mov(large_number2.Mod(rhs));
		}
	}

	return large_number1;
}


















