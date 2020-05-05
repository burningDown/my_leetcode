class Solution {
public:
    int numberOf2sInRange(int n) {
        int count = 0;
        for(long base = 1;n / base > 0;base *= 10)
            count += n / (base * 10) * base + (n / base % 10 == 2)*(n % base + 1) + (n / base % 10 > 2) * base;
        return count;
    }
};