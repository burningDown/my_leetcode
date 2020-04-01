class Solution {
private:
    void adjust(vector<int> &nums, int i, int l)
    {
        int maxIdx = i;
        if(2 * i + 1 < l && nums[2 * i + 1] > nums[maxIdx])
            maxIdx = 2 * i + 1;
        if(2 * i + 2 < l && nums[2 * i + 2] > nums[maxIdx])
            maxIdx = 2 * i + 2;
        if(maxIdx != i)
        {
            int temp = nums[maxIdx];
            nums[maxIdx] = nums[i];
            nums[i] = temp;
            adjust(nums, maxIdx, l);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int l = nums.size();
        for(int i=l/2-1;i>=0;i--)
            adjust(nums, i, l);
        
        int temp = nums[0];
        nums[0] = nums[l-1];
        nums[l-1] = temp;
        for(int i=1;i<k;i++)
        {
            adjust(nums, 0, l-i);
            temp = nums[0];
            nums[0] = nums[l-i-1];
            nums[l-i-1] = temp;
        }
        return nums[l-k];
    }
};