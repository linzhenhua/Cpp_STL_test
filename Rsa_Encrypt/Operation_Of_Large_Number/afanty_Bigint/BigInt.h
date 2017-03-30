/****************************************************************/
//大数运算库头文件：BigInt.h
//作者：afanty@vip.sina.com
//版本：1.0 (2003.4.26)
//说明：适用于MFC
/****************************************************************/

#define BI_MAXLEN 40
#define DEC 10
#define HEX 16

class CBigInt
{
public:
    int m_nSign;
    int m_nLength;
    unsigned long m_ulValue[BI_MAXLEN];

    CBigInt();
    ~CBigInt();

//基本操作与运算    
    CBigInt& Mov(CBigInt& A);
    CBigInt& Mov(unsigned __int64 A);
    int Cmp(CBigInt& A); 
    CBigInt Add(CBigInt& A);
    CBigInt Add(long A);
    CBigInt Sub(CBigInt& A);
    CBigInt Sub(long A);
    CBigInt Mul(CBigInt& A);
    CBigInt Mul(long A);
    CBigInt Div(CBigInt& A);
    CBigInt Div(long A);
    CBigInt Mod(CBigInt& A);
    long Mod(long A); 

//输入输出
    int InPutFromStr(CString& str, const unsigned int system);
    int OutPutToStr(CString& str, const unsigned int system);

//欧几里德算法求：Y=X.Euc(A)，使满足：YX mod A = 1

	CBigInt Euc(CBigInt& A);

//蒙哥马利算法求：Y=X.Mon(A,B)，使满足：X^A mod B = Y
    CBigInt Mon(CBigInt& A, CBigInt& B);
};