class Solution {
public:
    int climbStairs(int n) {
        int f1 = 1, f2 = 1, temp;
        for(int i=2;i<=n;i++)
        {
            temp = f1 + f2;
            f1 = f2;
            f2 = temp;
        }
        return f2;
    }
};