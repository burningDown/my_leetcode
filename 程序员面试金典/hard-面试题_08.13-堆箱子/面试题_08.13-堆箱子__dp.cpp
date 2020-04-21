bool cmp(vector<int> &v1, vector<int> &v2)
{
    return v1[0] > v2[0];
}
int max(int a, int b)
{
    return a > b ? a : b;
}

class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        const int l = box.size();
        vector<int> dp(l, 0);
        int res = 0;

        sort(box.begin(), box.end(), cmp);

        for(int i=l-1;i>=0;i--)
        {
            dp[i] = box[i][2];
            for(int j=i+1;j<l;j++)
                if(box[i][0] > box[j][0] && box[i][1] > box[j][1] && box[i][2] > box[j][2])
                    dp[i] = max(dp[i], box[i][2] + dp[j]);
            res = max(res, dp[i]);
        }
        
        return res;
    }
};