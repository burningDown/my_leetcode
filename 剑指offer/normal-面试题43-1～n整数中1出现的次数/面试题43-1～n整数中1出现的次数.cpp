class Solution {
public:
    int countDigitOne(int n) {
        if(n == 0)
            return 0;
        int base = (int)pow(10, (int)log10(n));
        int count = 0;
        while(base > 0)
        {
            count += (n / base / 10) * base;
            if(n / base % 10 > 1)
                count += base;
            else if(n / base % 10 == 1)
                count += n % base + 1;
            base /= 10;
        }
        return count;
    }
};