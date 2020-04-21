class Solution {
public:
    int multiply(int A, int B) {
        return B ? (B - ((B >> 1) << 1) ? A : 0) + multiply(A << 1, B >> 1) : 0;
    }
};