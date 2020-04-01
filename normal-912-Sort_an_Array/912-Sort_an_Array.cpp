class Solution {
private:
    void adjustDownward(vector<int> &nums, int i, int l)
    {
        int maxIdx;
        while(i < l)
        {
            maxIdx = i;
            if(2 * i + 1 < l && nums[2 * i + 1] > nums[maxIdx])
                maxIdx = 2 * i + 1;
            if(2 * i + 2 < l && nums[2 * i + 2] > nums[maxIdx])
                maxIdx = 2 * i + 2;
            if(maxIdx != i)
            {
                int temp = nums[maxIdx];
                nums[maxIdx] = nums[i];
                nums[i] = temp;
                i = maxIdx;
            }
            else
                break;
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        const int l = nums.size();
        for(int i=(l-1)/2;i>=0;i--)
            adjustDownward(nums, i, l);
        for(int i=l-1;i>0;i--)
        {
            int temp = nums[i];
            nums[i] = nums[0];
            nums[0] = temp;
            adjustDownward(nums, 0, i);
        }
        return nums;
    }
};