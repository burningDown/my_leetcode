class Solution {
public:
    int cuttingRope(int n) {
        int result = -1;

        for(int m = int(n / 2.71828)-2;m<=int(n / 2.718)+2;m++)
        {
            if(m <= 1)
                continue;
            int temp = pow(n/m, m - n % m) * pow(n/m+1, n%m);
            if(temp > result)
                result = temp;
        }
        return result;
    }
};