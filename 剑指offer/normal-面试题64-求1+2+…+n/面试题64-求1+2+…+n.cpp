class Solution {
public:
    int sumNums(int n) {
        int x;
        (x = n) && (x = n + sumNums(n - 1));
        return x;
    }
};