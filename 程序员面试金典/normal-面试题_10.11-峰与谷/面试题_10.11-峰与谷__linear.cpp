class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int l = nums.size();
        for(int i=1;i<l;i++)
        {
            if(i % 2 && nums[i] > nums[i-1] || !(i % 2) && nums[i] < nums[i-1])
                swap(nums[i-1], nums[i]);
        }
    }
};