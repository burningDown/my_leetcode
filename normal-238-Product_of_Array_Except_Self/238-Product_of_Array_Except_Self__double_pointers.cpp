class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int l = nums.size();
        if(l == 0)
            return {};
        
        int left = nums[0], right = nums[l-1];
        vector<int> res(l, 1);

        for(int i=1;i<l;i++)
        {
            res[i] *= left;
            res[l-i-1] *= right;
            left *= nums[i];
            right *= nums[l-i-1];
        }
        return res;
    }
};