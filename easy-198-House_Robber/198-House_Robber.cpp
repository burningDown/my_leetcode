class Solution {
public:
    int rob(vector<int>& nums) {
        const int l = nums.size();
        int dp0, dp1, dp2, temp;

        if(l == 0)
            return 0;
        if(l == 1)
            return nums[0];
        if(l == 2)
            return max(nums[0], nums[1]);

        dp0 = nums[0];
        dp1 = nums[1];
        dp2 = dp0 + nums[2];
        for(int i=3;i<l;i++)
        {
            temp = max(dp1, dp0) + nums[i];
            dp0 = dp1;
            dp1 = dp2;
            dp2 = temp;
        }
        
        return max(dp2, dp1);
    }
};