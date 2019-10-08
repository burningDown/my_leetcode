class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int dup = 0;
        int l = nums.size();
        for(int i=0;i<l;i++)
        {
            dup = nums[i];
            for(int j=i+1;j<l;j++)
            {
                if(dup == nums[j])
                    return dup;
            }
        }
        return dup;
    }
};