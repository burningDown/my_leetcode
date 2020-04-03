class Solution {
public:
    int fib(int n) {
        int dp[110];
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++)
            dp[i] = (dp[i-1] % int(1e9+7) + dp[i-2] % int(1e9+7)) % int(1e9+7);
        return dp[n];
    }
};