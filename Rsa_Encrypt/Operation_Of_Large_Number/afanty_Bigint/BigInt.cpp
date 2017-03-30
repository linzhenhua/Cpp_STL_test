/****************************************************************/
//大数运算库源文件：BigInt.cpp
//作者：afanty@vip.sina.com
//版本：1.0 (2003.4.26)
//说明：适用于MFC
/****************************************************************/

#include "stdafx.h"
#include "BigInt.h"

CBigInt::CBigInt()
{
	m_nSign=1;
	m_nLength=1;
	for(int i=0;i<BI_MAXLEN;i++)m_ulValue[i]=0;
}

CBigInt::~CBigInt()
{
}

int CBigInt::Cmp(CBigInt& A)
{
	if(m_nLength>A.m_nLength)return 1;
	if(m_nLength<A.m_nLength)return -1;
	for(int i=m_nLength-1;i>=0;i--)
	{
		if(m_ulValue[i]>A.m_ulValue[i])return 1;
		if(m_ulValue[i]<A.m_ulValue[i])return -1;
	}
	return 0;
}

CBigInt& CBigInt::Mov(CBigInt& A)
{
	m_nLength=A.m_nLength;
	for(int i=0;i<BI_MAXLEN;i++)m_ulValue[i]=A.m_ulValue[i];
	return *this;
}

CBigInt& CBigInt::Mov(unsigned __int64 A)
{
	if(A>0xffffffff)
	{
		m_nLength=2;
		m_ulValue[1]=(unsigned long)(A>>32);
		m_ulValue[0]=(unsigned long)A;
	}
	else
	{
		m_nLength=1;
		m_ulValue[0]=(unsigned long)A;
	}
	for(int i=m_nLength;i<BI_MAXLEN;i++)m_ulValue[i]=0;
	return *this;
}

CBigInt CBigInt::Add(CBigInt& A)
{
	CBigInt X;
	if(X.m_nSign==A.m_nSign)
	{
		X.Mov(*this);
		int carry=0;
	    unsigned __int64 sum=0;
	    if(X.m_nLength<A.m_nLength)X.m_nLength=A.m_nLength;
		for(int i=0;i<X.m_nLength;i++)
		{
			sum=A.m_ulValue[i];
			sum=sum+X.m_ulValue[i]+carry;
			X.m_ulValue[i]=(unsigned long)sum;
			if(sum>0xffffffff)carry=1;
			else carry=0;
		}
		if(X.m_nLength<BI_MAXLEN)
		{
			X.m_ulValue[X.m_nLength]=carry;
		    X.m_nLength+=carry;
		}
		return X;
	}
	else{X.Mov(A);X.m_nSign=1-X.m_nSign;return Sub(X);}
}

CBigInt CBigInt::Add(long A)
{
	CBigInt X;
	if((m_nSign*A)>=0)
	{
		X.Mov(*this);
		unsigned __int64 sum;
	    sum=A+X.m_ulValue[0];
		X.m_ulValue[0]=(unsigned long)sum;
		if(sum>0xffffffff)
		{
			int i=1;
			while(X.m_ulValue[i]==0xffffffff){X.m_ulValue[i]=0;i++;}
			X.m_ulValue[i]++;
			if(i<BI_MAXLEN)X.m_nLength=i+1;
		}
		return X;
	}
	else return Sub(-A);
}
		
CBigInt CBigInt::Sub(CBigInt& A)
{
	CBigInt X;
	if(m_nSign==A.m_nSign)
	{
		X.Mov(*this);
		int cmp=X.Cmp(A); 
		if(cmp==0){X.Mov(0);return X;}
		int len,carry=0;
		unsigned __int64 num;
		unsigned long *s,*d;
	    if(cmp>0){s=X.m_ulValue;d=A.m_ulValue;len=X.m_nLength;}
	    if(cmp<0){s=A.m_ulValue;d=X.m_ulValue;len=A.m_nLength;X.m_nSign=1-X.m_nSign;}
	    for(int i=0;i<len;i++)
		{
			if((s[i]-carry)>=d[i])
			{
				X.m_ulValue[i]=s[i]-carry-d[i];
				carry=0;
			}
			else
			{
				num=0x100000000+s[i];
				X.m_ulValue[i]=(unsigned long)(num-carry-d[i]);
				carry=1;
			}
		}
		while(X.m_ulValue[len-1]==0)len--;
		X.m_nLength=len;
		return X;
	}
	else{X.Mov(A);X.m_nSign=1-X.m_nSign;return Add(X);}
}

CBigInt CBigInt::Sub(long A)
{
	CBigInt X;
	if((m_nSign*A)>=0)
	{
		X.Mov(*this);
		if(X.m_ulValue[0]>=(unsigned long)A){X.m_ulValue[0]-=A;return X;}
		if(X.m_nLength==1){X.m_ulValue[0]=A-X.m_ulValue[0];X.m_nSign=1-X.m_nSign;return X;}
		unsigned __int64 num=0x100000000+X.m_ulValue[0];
		X.m_ulValue[0]=(unsigned long)(num-A);
		int i=1;
		while(X.m_ulValue[i]==0){X.m_ulValue[i]=0xffffffff;i++;}
		if(X.m_ulValue[i]==1)X.m_nLength--;
		X.m_ulValue[i]--;
		return X;
	}
	else return Add(-A);
}

CBigInt CBigInt::Mul(CBigInt& A)
{
	CBigInt X,Y;
	unsigned __int64 mul;
    unsigned long carry;
    for(int i=0;i<A.m_nLength;i++)
	{
		Y.m_nLength=m_nLength;
		carry=0;
		for(int j=0;j<m_nLength;j++)
		{
			mul=m_ulValue[j];
			mul=mul*A.m_ulValue[i]+carry;
			Y.m_ulValue[j]=(unsigned long)mul;
			carry=(unsigned long)(mul>>32);
		}
		if(carry&&(Y.m_nLength<BI_MAXLEN)){Y.m_nLength++;Y.m_ulValue[Y.m_nLength-1]=carry;}
		if(Y.m_nLength<BI_MAXLEN-i)
		{
			Y.m_nLength+=i;
		    for(int k=Y.m_nLength-1;k>=i;k--)Y.m_ulValue[k]=Y.m_ulValue[k-i];
		    for(k=0;k<i;k++)Y.m_ulValue[k]=0;
		}
		X.Mov(X.Add(Y));
	}
	if(m_nSign+A.m_nSign==1)X.m_nSign=0;
	else X.m_nSign=1;
	return X;
}

CBigInt CBigInt::Mul(long A)
{
	CBigInt X;
	unsigned __int64 mul;
	unsigned long carry=0;
	X.Mov(*this);
	for(int i=0;i<m_nLength;i++)
	{
		mul=m_ulValue[i];
		mul=mul*A+carry;
		X.m_ulValue[i]=(unsigned long)mul;
		carry=(unsigned long)((mul-X.m_ulValue[i])>>32);
	}
	if(carry&&(X.m_nLength<BI_MAXLEN)){X.m_nLength++;X.m_ulValue[X.m_nLength-1]=carry;}
	if(A<0)X.m_nSign=1-X.m_nSign;
	return X;
}

CBigInt CBigInt::Div(CBigInt& A)
{
	CBigInt X,Y,Z;
	int len;
	unsigned __int64 num,div;
	unsigned long carry=0;
	Y.Mov(*this);
	while(Y.Cmp(A)>0)
	{       
		if(Y.m_ulValue[Y.m_nLength-1]>A.m_ulValue[A.m_nLength-1])
		{
			len=Y.m_nLength-A.m_nLength;
			div=Y.m_ulValue[Y.m_nLength-1]/(A.m_ulValue[A.m_nLength-1]+1);
		}
		else if(Y.m_nLength>A.m_nLength)
		{
			len=Y.m_nLength-A.m_nLength-1;
			num=Y.m_ulValue[Y.m_nLength-1];
			num=(num<<32)+Y.m_ulValue[Y.m_nLength-2];
			if(A.m_ulValue[A.m_nLength-1]==0xffffffff)div=(num>>32);
			else div=num/(A.m_ulValue[A.m_nLength-1]+1);
		}
		else
		{
            X.Mov(X.Add(1));
			break;
		}
        Z.Mov(div);
		Z.m_nLength+=len;
		for(int i=Z.m_nLength-1;i>=len;i--)Z.m_ulValue[i]=Z.m_ulValue[i-len];
		for(i=0;i<len;i++)Z.m_ulValue[i]=0;
		X.Mov(X.Add(Z));
		Z.Mov(Z.Mul(A));
		Y.Mov(Y.Sub(Z));
	}
	if(Y.Cmp(A)==0)X.Mov(X.Add(1));
	if(m_nSign+A.m_nSign==1)X.m_nSign=0;
	else X.m_nSign=1;
	return X;
}

CBigInt CBigInt::Div(long A)
{
	CBigInt X;
	X.Mov(*this);
	if(X.m_nLength==1){X.m_ulValue[0]=X.m_ulValue[0]/A;return X;}
	unsigned __int64 div,mul;
	unsigned long carry=0;
	for(int i=X.m_nLength-1;i>=0;i--)
	{
		div=carry;
		div=(div<<32)+X.m_ulValue[i];
		X.m_ulValue[i]=(unsigned long)(div/A);
		mul=(div/A)*A;
		carry=(unsigned long)(div-mul);
	}
	if(X.m_ulValue[X.m_nLength-1]==0)X.m_nLength--;
	if(A<0)X.m_nSign=1-X.m_nSign;
	return X;
}

CBigInt CBigInt::Mod(CBigInt& A)
{
	CBigInt X,Y;
	int len;
	unsigned __int64 num,div;
	unsigned long carry=0;
	X.Mov(*this);
	while(X.Cmp(A)>0)
	{       
		if(X.m_ulValue[X.m_nLength-1]>A.m_ulValue[A.m_nLength-1])
		{
			len=X.m_nLength-A.m_nLength;
			div=X.m_ulValue[X.m_nLength-1]/(A.m_ulValue[A.m_nLength-1]+1);
		}
		else if(X.m_nLength>A.m_nLength)
		{
			len=X.m_nLength-A.m_nLength-1;
			num=X.m_ulValue[X.m_nLength-1];
			num=(num<<32)+X.m_ulValue[X.m_nLength-2];
			if(A.m_ulValue[A.m_nLength-1]==0xffffffff)div=(num>>32);
			else div=num/(A.m_ulValue[A.m_nLength-1]+1);
		}
		else
		{
			X.Mov(X.Sub(A));
			break;
		}
        Y.Mov(div);
		Y.Mov(Y.Mul(A));
		Y.m_nLength+=len;
		for(int i=Y.m_nLength-1;i>=len;i--)Y.m_ulValue[i]=Y.m_ulValue[i-len];
		for(i=0;i<len;i++)Y.m_ulValue[i]=0;
		X.Mov(X.Sub(Y));
	}
	if(X.Cmp(A)==0)X.Mov(0);
	return X;
}

long CBigInt::Mod(long A)
{
	if(m_nLength==1)return(m_ulValue[0]%A);
	unsigned __int64 div;
	unsigned long carry=0;
	for(int i=m_nLength-1;i>=0;i--)
	{
		div=carry*0x100000000+m_ulValue[i];
		carry=(unsigned long)(div-((div/A)*A));
	}
	return carry;
}

int CBigInt::InPutFromStr(CString& str, const unsigned int system=DEC)
{
    int len=str.GetLength();
	Mov(0);
	for(int i=0;i<len;i++)
    {
       	Mov(Mul(system));
		int k=str[i]-48;
		Mov(Add(k));
  	}
  	return 0;
}

int CBigInt::OutPutToStr(CString& str, const unsigned int system=DEC)
{
	str="";
	char ch;
	CBigInt X;
	X.Mov(*this);
	while(X.m_ulValue[X.m_nLength-1]>0)
	{
		ch=X.Mod(system)+48;
		str.Insert(0,ch);
        X.Mov(X.Div(system));
	}
	return 0;
}	
			
CBigInt CBigInt::Euc(CBigInt& A)
{
	CBigInt X,Y;
	X.Mov(*this);
	Y.Mov(A);
	if((X.m_nLength==1)&&(X.m_ulValue[0]==1))return X;
	if((Y.m_nLength==1)&&(Y.m_ulValue[0]==1)){X.Mov(X.Sub(1));return X;}
	if(X.Cmp(Y)==1)X.Mov(X.Mod(Y));
	else Y.Mov(Y.Mod(X));
	X.Mov(X.Euc(Y));
    Y.Mov(*this);
	if(Y.Cmp(A)==1)
	{
		X.Mov(X.Mul(Y));
		X.Mov(X.Sub(1));
		X.Mov(X.Div(A));
	}
	else
	{
		X.Mov(X.Mul(A));
		X.Mov(X.Add(1));
		X.Mov(X.Div(Y));
	}
	return X;
}
			
CBigInt CBigInt::Mon(CBigInt& A, CBigInt& B)
{
	CBigInt X,Y,Z;
	X.Mov(1);
	Y.Mov(*this);
    Z.Mov(A);
	while((Z.m_nLength!=1)||Z.m_ulValue[0])
	{
		if(Z.m_ulValue[0]&1)
		{
			Z.Mov(Z.Sub(1));
			X.Mov(X.Mul(Y));
			X.Mov(X.Mod(B));
		}
		else
		{
			Z.Mov(Z.Div(2));
			Y.Mov(Y.Mul(Y));
			Y.Mov(Y.Mod(B));
		}
	}
    return X;
}
	
