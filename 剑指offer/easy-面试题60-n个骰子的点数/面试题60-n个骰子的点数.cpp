class Solution {
private:
    int dp[15][90];
public:
    vector<double> twoSum(int n) {
        const int &s = 6 * n;
        const double pow_6_n = pow(6, n);
        vector<double> result;

        result.reserve(6*n+10);
        memset(dp, 0, 15*90);

        for(int i=1;i<=6;i++)
            dp[1][i] = 1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=s;j++)
            {
                for(int k=j-6>=0?j-6:0;k<j;k++)
                    dp[i][j] += dp[i-1][k];
            }
        }

        for(int i=n;i<=s;i++)
            result.push_back(double(dp[n][i])/pow_6_n);
        return result;
    }
};