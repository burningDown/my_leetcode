class Solution {
public:
    int countDigitOne(int n) {
        long base = 1;
        int res = 0;
        int temp = n;

        while(n / base > 0)
        {
            int b = n / base % 10;
            if(b < 1)
                res += (n / (base * 10)) * base;
            else if(b == 1)
                res += (n / (base * 10)) * base + n % base + 1;
            else
                res += (n / (base * 10) + 1) * base;
            base *= 10;
        }

        return res;
    }
};