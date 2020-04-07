inline int min(int a, int b, int c = INT_MAX)
{
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int l1 = word1.size();
        const int l2 = word2.size();

        if(l1 == 0 || l2 == 0)
            return l1 == 0 ? l2 : l1;
        vector<vector<int>> dp(l1 + 5, vector<int>(l2 + 5, 0));
        
        for(int i=0;i<l1;i++)
            dp[i][l2] = l1 - i;
        for(int j=0;j<l2;j++)
            dp[l1][j] = l2 - j;
        for(int i = l1 - 1;i >= 0;i--)
        {
            for(int j = l2 - 1;j >= 0;j--)
            {
                if(word1[i] == word2[j])
                    dp[i][j] = min(dp[i+1][j]+1, dp[i][j+1]+1, dp[i+1][j+1]);
                else
                    dp[i][j] = min(dp[i+1][j]+1, dp[i][j+1]+1, dp[i+1][j+1]+1);
            }
        }
        return dp[0][0];
    }
};