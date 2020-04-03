class Solution {
private:
    int binaryFind(vector<int> &nums, int start, int end)
    {
        if(start >= end-1)
            return start;
        int mid = (start + end) / 2;
        if(nums[mid] == mid)
            return binaryFind(nums, mid, end);
        else
            return binaryFind(nums, start, mid);
    }
public:
    int missingNumber(vector<int>& nums) {
        if(nums[0] == 1)
            return 0;
        else if(nums[nums.size() - 1] == nums.size() - 1)
            return nums.size();

        return nums[binaryFind(nums, 0, nums.size()-1)] + 1;
    }
};