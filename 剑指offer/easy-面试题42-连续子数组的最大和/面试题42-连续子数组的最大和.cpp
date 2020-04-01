class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = nums[0];
        for(int i : nums)
        {
            sum = sum < 0 ? i : sum + i;
            if(maxSum < sum)
                maxSum = sum;
        }
        return maxSum;
    }
};