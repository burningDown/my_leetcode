class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int l = nums.size();
        if(l == 0)
            return {};
        
        vector<int> pre(l, 0);
        vector<int> suf(l, 0);
        vector<int> res(l, 0);

        pre[0] = suf[l-1] = 1;
        for(int i=1;i<l;i++)
        {
            pre[i] = pre[i-1] * nums[i-1];
            suf[l-i-1] = suf[l-i] * nums[l-i];
        }
        for(int i=0;i<l;i++)
            res[i] = pre[i] * suf[i];

        return res;
    }
};