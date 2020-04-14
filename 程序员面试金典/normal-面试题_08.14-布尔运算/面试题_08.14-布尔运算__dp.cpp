class Solution {
public:
    int countEval(string s, int result) {
        const int l = s.size();
        int dp[50][50][2] = { 0 };
        
        for(int i=0;i<l;i+=2)
        {
            dp[i][i][0] = int(s[i] - '0' == 0);
            dp[i][i][1] = int(s[i] - '0' == 1);
        }

        for(int w=2;w<l;w+=2)
        {
            for(int end=w;end<l;end+=2)
            {
                int start = end - w;
                for(int i=start+1;i<end;i+=2)
                {
                    switch(s[i])
                    {
                    case '&':
                        dp[start][end][1] += dp[start][i-1][1] * dp[i+1][end][1];
                        dp[start][end][0] += dp[start][i-1][1] * dp[i+1][end][0] + dp[start][i-1][0] * dp[i+1][end][1] + dp[start][i-1][0] * dp[i+1][end][0];
                        break;
                    case '|':
                        dp[start][end][1] += dp[start][i-1][1] * dp[i+1][end][1] + dp[start][i-1][0] * dp[i+1][end][1] + dp[start][i-1][1] * dp[i+1][end][0];
                        dp[start][end][0] += dp[start][i-1][0] * dp[i+1][end][0];
                        break;
                    case '^':
                        dp[start][end][1] += dp[start][i-1][1] * dp[i+1][end][0] + dp[start][i-1][0] * dp[i+1][end][1];
                        dp[start][end][0] += dp[start][i-1][0] * dp[i+1][end][0] + dp[start][i-1][1] * dp[i+1][end][1];
                        break;
                    }
                }
            }
        }
        return dp[0][l-1][result];
    }
};