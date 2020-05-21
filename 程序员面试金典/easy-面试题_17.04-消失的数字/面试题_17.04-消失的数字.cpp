class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int l = nums.size();
        int res = l;
        for(int i=0;i<l;i++)
        {
            res ^= nums[i];
            res ^= i;
        }
        return res;
    }
};