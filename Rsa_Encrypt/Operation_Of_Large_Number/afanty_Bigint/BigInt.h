/****************************************************************/
//���������ͷ�ļ���BigInt.h
//���ߣ�afanty@vip.sina.com
//�汾��1.0 (2003.4.26)
//˵����������MFC
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

//��������������    
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

//�������
    int InPutFromStr(CString& str, const unsigned int system);
    int OutPutToStr(CString& str, const unsigned int system);

//ŷ������㷨��Y=X.Euc(A)��ʹ���㣺YX mod A = 1

	CBigInt Euc(CBigInt& A);

//�ɸ������㷨��Y=X.Mon(A,B)��ʹ���㣺X^A mod B = Y
    CBigInt Mon(CBigInt& A, CBigInt& B);
};