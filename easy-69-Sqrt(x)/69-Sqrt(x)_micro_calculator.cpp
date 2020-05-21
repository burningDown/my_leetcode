class Solution {
public:
    int mySqrt(int x) {
        int res = exp(0.5 * log(x));

        return res < 46340 && (res + 1) * (res + 1) <= x ? res + 1 : res;
    }
};