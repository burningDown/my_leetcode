class Solution {
public:
    int findNthDigit(int n) {
        long base = 10;

        if(n < 10)
            return n;
        n -= 10;
        
        for(int i=2;;i++)
        {
            if(n < i*(base*10-base))
                return ((n/i+base) / (int)pow(10, i-n%i-1))%10;
            n -= i*(base*10-base);
            base *= 10;
        }
    }
};