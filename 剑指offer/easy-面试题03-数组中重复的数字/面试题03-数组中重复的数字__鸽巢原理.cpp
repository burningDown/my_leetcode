class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        const int l = nums.size();
        int temp;
        for(int i=0;i<l;i++)
        {
            while(nums[i] != i)
            {
                if(nums[i] == nums[nums[i]])
                    return nums[i];
                
                temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return -1;
    }
};