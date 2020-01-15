class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = log2(x > y ? x : y);
        int count=0;
        for(int i=0;i<=n;i++, x=x>>1, y=y>>1)
            count += (x&1)^(y&1);
        return count;
    }
};