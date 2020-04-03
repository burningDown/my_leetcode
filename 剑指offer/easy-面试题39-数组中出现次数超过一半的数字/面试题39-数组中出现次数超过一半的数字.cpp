class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int currentNum = nums[0];
        const int l = nums.size();
        for(int i=1;i<l;i++)
        {
            if(nums[i] == currentNum)
                count++;
            else
            {
                count--;
                if(count < 0)
                {
                    count = 0;
                    currentNum = nums[i];
                }
            }
        }
        return currentNum;
    }
};