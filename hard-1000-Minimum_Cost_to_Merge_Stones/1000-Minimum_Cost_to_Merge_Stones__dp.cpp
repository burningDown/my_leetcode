class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int dp[35][35][35] = { 0 };
        int integralMap[35] = { 0 };
        const int n = stones.size();
        if(K > 1 && (n - K) % (K - 1) != 0)
            return -1;

        integralMap[1] = stones[0];
        for(int i=1;i<n;i++)
            integralMap[i+1] = integralMap[i] + stones[i];
        
        for(int len=0;len<n;len++)
        {
            for(int l=0;l+len<n;l++)
            {
                int r = l + len + 1;    // 很重要，涉及到dp表的更新顺序问题，必须按照区间长度来更新而不是分别遍历左右边界
                
                for(int k=2;k<=K;k++)
                {
                    dp[l][r][k] = dp[l][l][1] + dp[l+1][r][k-1];
                    for(int i=l;i<r-k+2;i+=K-1)
                    {
                        dp[l][r][k] = min(dp[l][r][k], dp[l][i][1] + dp[i+1][r][k-1]);
                    }
                }
                dp[l][r][1] = dp[l][r][K] + integralMap[r+1] - integralMap[l];
            }
        }

        return dp[0][n-1][1];
    }
};