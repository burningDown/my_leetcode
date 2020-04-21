class Solution {
public:
    int add(int a, int b) {
        unsigned int c = 0;
        unsigned int mask = -1;
        unsigned int sum = 0;
        while(a || b)
        {
            if( (a^b^c)&1 )
                sum |= mask;
            else
                sum &= (mask-1);
            mask <<= 1;
            c = (a&b)|(a&c)|(b&c);
            a = (unsigned int)(a) >> 1;
            b = (unsigned int)(b) >> 1;
        }
        if(c&1)
        {
            sum |= mask;
            mask <<= 1;
        }
        sum &= (~mask);
        return sum;
    }
};