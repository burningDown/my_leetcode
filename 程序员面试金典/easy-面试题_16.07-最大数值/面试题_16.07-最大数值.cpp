class Solution {
public:
    int maximum(int a, int b) {
        int m;
        (long(a) - long(b)) & ((unsigned long)(1) << sizeof(unsigned long) * 8 - 1) && (m = b);
        (long(b) - long(a)) & ((unsigned long)(1) << sizeof(unsigned long) * 8 - 1) && (m = a);
        return m;
    }
};