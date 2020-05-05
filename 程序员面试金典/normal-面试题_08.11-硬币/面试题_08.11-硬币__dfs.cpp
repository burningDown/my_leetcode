class Solution {
public:
    int waysToChange(int n) {
        vector<vector<int>> dp(n+5, vector<int>(4, 0));

        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=3;j++)
            {
                if(i >= 25 && j >= 3)
                    dp[i][j] = (dp[i][j] + dp[i-25][3]) % 1000000007;
                if(i >= 10 && j >= 2)
                    dp[i][j] = (dp[i][j] + dp[i-10][2]) % 1000000007;
                if(i >= 5 && j >= 1)
                    dp[i][j] = (dp[i][j] + dp[i-5][1]) % 1000000007;
                if(i >= 1 && j >= 0)
                    dp[i][j] = (dp[i][j] + dp[i-1][0]) % 1000000007;
            }
        }
        return dp[n][3];
    }
};