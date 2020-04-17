class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0)
            return true;
        vector<bool> dp(nums.size(), false);
        const int l = nums.size();

        dp[0] = true;
        for(int i=0;i<l;i++)
        {
            if(dp[i])
            {
                for(int j=1;j<=nums[i]&&i+j<l;j++)
                {
                    dp[i+j] = true;
                }
            }
        }
        return dp[l-1];
    }
};