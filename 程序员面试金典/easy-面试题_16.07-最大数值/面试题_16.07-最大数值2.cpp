class Solution {
public:
    int maximum(int a, int b) {
        return a * !((unsigned long)(long(a) - long(b)) >> 63) + b * ((unsigned long)(long(a) - long(b)) >> 63);
    }
};