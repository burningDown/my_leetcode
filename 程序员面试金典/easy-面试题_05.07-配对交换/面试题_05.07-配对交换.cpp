class Solution {
public:
    int exchangeBits(int num) {
        int mask = 1;
        while(~(mask-1)&num)
        {
            num ^= (num&mask) << 1;
            num ^= (num&(mask<<1)) >> 1;
            num ^= (num&mask) << 1;
            mask <<= 2;
        }
        return num;
    }
};