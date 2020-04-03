class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        vector<int> result(2, INT_MIN);
        while(i < j)
        {
            if(nums[i] + nums[j] < target)
                i++;
            else if(nums[i] + nums[j] > target)
                j--;
            else
            {
                result[0] = nums[i];
                result[1] = nums[j];
                break;
            }
        }
        return result;
    }
};