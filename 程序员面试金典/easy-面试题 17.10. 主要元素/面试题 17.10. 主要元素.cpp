class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int count = 1;
        const int l = nums.size();

        for(int i=1;i<l;i++)
        {
            if(nums[i] == major)
            {
                count++;
            }
            else
            {
                count--;
                if(count == 0)
                {
                    major = nums[i];
                    count = 1;
                }
            }
        }

        count = 0;
        for(int i=0;i<l;i++)
        {
            if(nums[i] == major)
                count++;
        }
        return 2 * count > l ? major : -1;
    }
};