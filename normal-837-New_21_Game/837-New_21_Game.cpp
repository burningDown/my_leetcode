class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K == 0)
            return 1;
        
        double dp[20000] = { 0.0 };
        double res = 0.0;

        dp[0] = 1.0;
        dp[1] = 1.0 / W;
        for(int i=2;i<=K;i++)
        {
            dp[i] = dp[i-1] / W + dp[i-1];
            if(i > W)
                dp[i] -= dp[i-W-1] / W;
        }
        for(int i=K+1;i<=K+W-1;i++)
        {
            dp[i] = dp[i-1];
            if(i-W-1 >= 0)
                dp[i] -= dp[i-W-1] / W;
        }
        
        for(int i=K;i<=N;i++)
            res += dp[i];
        
        return res;
    }
};