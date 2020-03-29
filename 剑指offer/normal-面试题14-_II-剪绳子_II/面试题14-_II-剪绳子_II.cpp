class Solution {
private:
    long binaryPowInMod(int a, int n, int mod)
    {
        long res = 1;
        while(n != 0)
        {
            if(n & 1)
                res = ((long)res*a) % mod;
            a = ((long)a*a) % mod;
            n >>= 1;
        }
        return res;
    }
public:
    int cuttingRope(int n) {
        if(n <= 3)
            return n-1;
        else if(n == 4)
            return 4;
        else if(n % 3 == 0)
            return binaryPowInMod(3, n/3, 1e9+7);
        else if(n % 3 == 1)
            return binaryPowInMod(3, n/3-1, 1e9+7)*4 % int(1e9+7);
        else
            return binaryPowInMod(3, n/3, 1e9+7)*2 % int(1e9+7);
    }
};