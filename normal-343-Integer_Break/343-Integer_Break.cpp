class Solution {
public:
    int integerBreak(int n) {
        int res = 1;

        if(n == 2)
            return 1;
        else if(n == 3)
            return 2;
        else if(n == 4)
            return 4;
        else
        {
            while(n > 4)
            {
                res *= 3;
                n -= 3;
            }
            res *= n;
        }
        return res;
    }
};