class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = nums.size();
        int fast = 0, slow = 0;
        while(1)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow)
                break;
        }
        slow = 0;
        while(1)
        {
            fast = nums[fast];
            slow = nums[slow];
            if(fast == slow)
                break;
        }
        return fast;
    }
};