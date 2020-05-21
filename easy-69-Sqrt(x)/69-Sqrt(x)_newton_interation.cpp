inline double newtonInteration(double x, double target)
{
    return 0.5 * (x + target / x);
}

class Solution {
public:
    int mySqrt(int x) {
        double x1 = 0, x2 = x;
        while(abs(x2 - x1) > 0.9)
        {
            x1 = x2;
            x2 = newtonInteration(x2, x);
        }
        return x2;
    }
};