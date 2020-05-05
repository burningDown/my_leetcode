bool cmp(vector<int> &v1, vector<int> &v2)
{
    return v1[0] > v2[0];
}

class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        const int l = height.size();

        if(l == 0)
            return 0;

        vector<vector<int>> unionParameter(l);
        vector<int> dp(l, 1);
        int maxH = 1;

        for(int i=0;i<l;i++)
            unionParameter[i] = {height[i], weight[i]};
        
        sort(unionParameter.begin(), unionParameter.end(), cmp);

        dp[l-1] = 1;
        for(int i=l-1;i>=0;i--)
            for(int j=i+1;j<l;j++)
            {
                if(unionParameter[j][0] < unionParameter[i][0] && unionParameter[j][1] < unionParameter[i][1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxH = max(maxH, dp[i]);
                }
            }

        return maxH;
    }
};