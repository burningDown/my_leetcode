class Solution {
public:
    int jump(vector<int>& nums) {
        const int l = nums.size();
        vector<int> dp(l, l+5);
        int minStep, i, j;

        dp[l-1] = 0;
        for(i=l-2;i>=0;i--)
            for(j=min(i+nums[i], l-1);j>=i;j--)
                dp[i] = min(dp[i], dp[j]+1);

        return dp[0];
    }
};