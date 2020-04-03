class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        if(j < 0)
            return nums;
        int candidate = nums[0];
        while(i < j)
        {
            while(i < j)
            {
                if(nums[j] % 2 == 1)
                {
                    nums[i] = nums[j];
                    i++;
                    break;
                }
                j--;
            }
            while(i < j)
            {
                if(nums[i] % 2 == 0)
                {
                    nums[j] = nums[i];
                    j--;
                    break;
                }
                i++;
            }
        }
        nums[i] = candidate;
        return nums;
    }
};