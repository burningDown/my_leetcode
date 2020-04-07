class Solution {
public:
    int add(int a, int b) {
        unsigned int s = a ^ b, c = 0;  // c: 进位
        for(unsigned int i=-1;i!=0;i>>=1)
        {
            c >>= 1;
            c |= ((a&b|a&c>>30|b&c>>30)&1)<<31;
            a >>= 1;
            b >>= 1;
        }
        s ^= c<<1;
        return (int)s;  // 加法器s = a ^ b ^ c
    }
};