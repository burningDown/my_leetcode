class Solution {
public:
    int maxA(int N) {
        int dp[55];

        for(int i=1;i<=N;i++)
        {
            dp[i] = i;
            for(int j=1;j<=i-2;j++)
            {
                if((i - j - 1) * dp[j] > dp[i])
                    dp[i] = (i - j - 1) * dp[j];
            }
        }
        return dp[N];
    }
};