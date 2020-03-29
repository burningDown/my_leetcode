class Solution {
private:
    double binaryPow(double x, long n)
    {
        double res = 1.0;
        if(n < 0)
        {
            n = -n;
            x = 1/x;
        }

        while(n > 0)
        {
            if(n & 1)
                res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
public:
    double myPow(double x, int n) {
        return binaryPow(x, n);
    }
};