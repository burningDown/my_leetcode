class Solution {
private:
    int trackback(vector<int> &slices, int dp[500][500][2], int start, int l, bool visit0, int count)
    {
        if(dp[start][count][(int)visit0] > 0)
            return dp[start][count][(int)visit0];

        if(start >= l || count >= l)
            return 0;
        
        int res = 0;
        for(int i=start;i<l-1;i++)
        {
            res = max(res, slices[i] + trackback(slices, dp, i + 2, l, visit0, count + 3));
        }
        if(!visit0)
        {
            res = max(res, slices[l-1]);
        }

        dp[start][count][(int)visit0] = res;
        return res;
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int res = 0;
        const int l = slices.size();
        int dp[500][500][2] = { 0 };

        for(int i=0;i<l;i++)
        {
            res = max(res, trackback(slices, dp, i, l, i == 0, 0));
        }
        return res;
    }
};