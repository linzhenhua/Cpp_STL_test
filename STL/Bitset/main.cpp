#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

void BitSet()
{
    bitset<16> bit_set(0x00ff);
    bitset<16> bit_set1(0xff00);

    cout << bit_set << endl;           //打印0000000011111111

    cout << bit_set.size() << endl;    //有多少位

    cout << bit_set.count() << endl;   //统计为1的个数

    cout << bit_set.any() << endl;     //是否有位被设置为1

    cout << bit_set.none() << endl;

    cout << bit_set.test(5) << endl;   //从后面读取，比如：第15位为计算机上的0位

    cout << (bit_set == bit_set1) << endl;    //为啥要加括号，因为<<的优先级大于==

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










