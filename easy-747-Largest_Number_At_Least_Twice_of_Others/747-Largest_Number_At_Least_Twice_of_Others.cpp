class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIdx = 0;
        const int l = nums.size();
        for(int i=0;i<l;i++)
        {
            if(nums[i] > nums[maxIdx])
                maxIdx = i;
        }
        for(int i=0;i<l;i++)
        {
            if(i != maxIdx && nums[i] * 2 > nums[maxIdx])
                return -1;
        }
        return maxIdx;
    }
};