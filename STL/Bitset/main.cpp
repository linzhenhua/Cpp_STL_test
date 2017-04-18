#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

void BitSet()
{
    bitset<16> bit_set(0x00ff);
    bitset<16> bit_set1(0xff00);

    cout << bit_set << endl;           //��ӡ0000000011111111

    cout << bit_set.size() << endl;    //�ж���λ

    cout << bit_set.count() << endl;   //ͳ��Ϊ1�ĸ���

    cout << bit_set.any() << endl;     //�Ƿ���λ������Ϊ1

    cout << bit_set.none() << endl;

    cout << bit_set.test(5) << endl;   //�Ӻ����ȡ�����磺��15λΪ������ϵ�0λ

    cout << (bit_set == bit_set1) << endl;    //ΪɶҪ�����ţ���Ϊ<<�����ȼ�����==

    cout << (bit_set != bit_set1) << endl;

    //cout << bit_set.set() << endl;

    cout << bit_set.set(13) << endl;

    cout << bit_set.set(13, 0) << endl;

    cout << bit_set.flip() << endl;

    cout << ( bit_set1 ^= bit_set ) << endl;

    cout << bit_set.to_ulong() << endl;

    cout << bit_set.to_string() << endl;

}

int main()
{
    BitSet();

    return 0;
}










