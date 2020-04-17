class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0)
            return true;
        const int l = nums.size();
        int left = 0, right = 0, maxDist, i;
        right = nums[0];
        while(right < l-1)
        {
            maxDist = 0;
            for(i=left;i<=right;i++)
            {
                if(i + nums[i] > maxDist)
                    maxDist = i + nums[i];
            }
            if(right == maxDist)
                return false;
            left = right;
            right = maxDist;
        }
        return true;
    }
};