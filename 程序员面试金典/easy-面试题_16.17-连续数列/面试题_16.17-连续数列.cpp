class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxCount = INT_MIN, count = 0;
        for(int & i : nums)
        {
            count = max(count + i, i);
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};