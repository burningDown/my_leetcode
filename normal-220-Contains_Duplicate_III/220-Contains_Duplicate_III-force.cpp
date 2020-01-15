class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        const int &l = nums.size();
        for(int i=0;i<l;i++)
        {
            for(int j=i+1;j<l&&j-i<=k;j++)
            {
                if(abs((long long)(nums[i])-(long long)(nums[j]))<=t)
                    return true;
            }
        }
        return false;
    }
};