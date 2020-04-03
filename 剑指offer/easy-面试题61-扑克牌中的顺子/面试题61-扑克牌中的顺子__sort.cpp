class Solution {
public:
    bool isStraight(vector<int>& nums) {
        if(nums.size() == 0)
            return true;
        sort(nums.begin(), nums.end());
        
        int count0 = 0;
        const int l = nums.size();
        for(int i=0;i<l;i++)
        {
            if(nums[i] == 0)
                count0++;
            else
                break;
        }
        for(int i=count0+1;i<l;i++)
        {
            if(nums[i] > nums[i-1] + 1)
            {
                count0 -= nums[i] - nums[i-1] - 1;
                if(count0 < 0)
                    return false;
            }
            else if(nums[i] == nums[i-1])
                return false;
        }
        return true;
    }
};