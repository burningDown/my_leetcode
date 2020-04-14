class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        // unsigned int mask = -1;
        // mask <<= j-i+1;
        // mask = ~mask;
        // mask <<= i;
        // mask = ~mask;

        // return (N & mask) | (unsigned int)(M) << i;
        return (N & ( ~((~((unsigned int)(-1)<<j-i+1))<<i) ) ) | (unsigned int)(M) << i;

    }
};