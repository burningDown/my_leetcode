bool cmp(vector<int> &v1, vector<int> &v2)
{
    return v1[0] > v2[0];
}

class Solution {
private:
    int backtrack(vector<vector<int>> &box, vector<int> &dp, int lastIdx)
    {
        int maxHight = 0, h, maxIdx = -1;
        const int l = box.size();
        for(int i=lastIdx+1;i<l;i++)
        {
            if(lastIdx < 0 || box[i][0] < box[lastIdx][0] && box[i][1] < box[lastIdx][1] && box[i][2] < box[lastIdx][2])
            {
                if(dp[i] >= 0)
                    h = dp[i];
                else
                {
                    h = box[i][2] + backtrack(box, dp, i);
                    dp[i] = h;
                }
                
                if(h > maxHight)
                {
                    maxIdx = i;
                    maxHight = h;
                }
            }
        }
        
        if(maxIdx >= 0)
            dp[maxIdx] = maxHight;
        return maxHight;
    }
public:
    int pileBox(vector<vector<int>>& box) {
        const int l = box.size();
        vector<bool> visited(l, false);
        vector<int> dp(l, -1);

        sort(box.begin(), box.end(), cmp);

        return backtrack(box, dp, -1);
    }
};