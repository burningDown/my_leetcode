class Solution {
public:
    int numWays(int n) {
        int dp[100 + 10] = { 0 };
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++)
            dp[i] = (dp[i-1] + dp[i-2]) % int(1e9+7);
        return dp[n];
    }
};