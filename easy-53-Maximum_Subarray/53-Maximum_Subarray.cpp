class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxCount = INT_MIN, count = 0;

        for(int & i : nums)
        {
            count += i;

            maxCount = max(maxCount, count);

            if(count < 0)
                count = 0;
        }

        return maxCount;
    }
};