class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;

        if(n < 0)
        {
            x = 1 / x;
            if(n == INT_MIN)
            {
                res = x;
                n = INT_MAX;
            }
            else
                n = -n;
        }
        while(n)
        {
            if(n & 1)
                res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
};