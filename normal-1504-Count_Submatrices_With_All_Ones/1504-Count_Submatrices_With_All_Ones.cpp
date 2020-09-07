class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int dp[200][200] = { 0 };
        const int h = mat.size();
        const int w = mat[0].size();
        int res = 0;

        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(mat[i][j])
                {
                    dp[i][j] = 1 + (i > 0 ? dp[i-1][j] : 0);
                    int minW = dp[i][j];
                    for(int k=j;k>=0 && dp[i][k]>0;k--)
                    {
                        minW = min(minW, dp[i][k]);
                        res += minW;
                    }
                }
            }
        }
        
        return res;
    }
};